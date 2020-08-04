module CPU(
    input wire clk,
    input wire rst,
    output reg useless
);

wire [7:0] alu_a;
wire [7:0] alu_b;
wire [7:0] alu_out;
wire [3:0] alu_op;
wire alu_carry_or_borrow;
wire alu_vf_we;

ALU alu (
    .a(alu_a), .b(alu_b), .op(alu_op), .out(alu_out), .carry_or_borrow(alu_carry_or_borrow), .vf_we(alu_vf_we)
);

reg [11:0] pc_preload;
reg pc_preload_stb;
reg pc_jump_next_stb;
wire pc_inc_stb;
reg [11:0] pc_out;

PC pc (
    .clk(clk), .rst(rst), .preload(pc_preload), .preload_stb(pc_preload_stb), .jump_next_stb(pc_jump_next_stb), .inc_stb(pc_inc_stb), .out(pc_out)
);

reg [15:0] ir;
//reg [11:0]  i; // used for indirect addressing
reg [7:0]  vx [0:15];
reg [7:0]  memory [0:4095]; // this is our main memory
wire [11:0] mem_addr;
reg [7:0]  mem_in;
reg [7:0]  mem_out;
reg mem_we;

localparam FETCH_1 = 0, FETCH_2 = 1, DECODE = 2, EXECUTE = 3;
reg [3:0] state;

// ALU operations are encoded in the 4 LSBs
assign alu_op = ir[3:0];

// multiplex ALU inputs over VX registers
assign alu_a  = vx[ir[11:8]];
assign alu_b  = vx[ir[7:4]];

// multiplex memory address from pc and (TODO) data address
assign mem_addr = (state == FETCH_1 || state == FETCH_2) ? pc_out : 0;
assign pc_inc_stb = (state == FETCH_1 || state == FETCH_2);

// this should get inferred as block ram
always @(negedge clk) begin
    if(mem_we) begin
        memory[mem_addr] <= mem_in;
    end
    else begin
        mem_out <= memory[mem_addr];
    end
end

initial $readmemh("chip8.rom", memory);

always @(posedge clk) begin
    if(rst) begin
        state <= FETCH_1;
        mem_in <= 0;
    end else begin
        case(state)
        FETCH_1: begin
            mem_we   <= 0;
            ir[15:8] <= mem_out;
            state    <= FETCH_2;
        end
        FETCH_2: begin
            mem_we   <= 0;
            ir[7:0]  <= mem_out;
            state    <= DECODE;
        end
        DECODE: begin
            case(ir[15:12]) 
                4'h0: begin
                    useless <= 0; // TODO: implement SYS, CLS and RET
                end
                4'h1: begin
                    pc_preload <= ir[11:0]; // unconditional JUMP
                    pc_preload_stb <= 1'd1;
                end
                4'h2: begin
                    useless <= 0; // TODO: implement CALL
                end
                4'h3: begin
                    if(vx[ir[11:8]] == ir[7:0]) begin // skips next instruction if Vx == kk
                        pc_jump_next_stb <= 1'd1;
                    end
                end
                4'h4: begin
                    if(vx[ir[11:8]] != ir[7:0]) begin // skips next instruction if Vx != kk
                        pc_jump_next_stb <= 1'd1;
                    end
                end
                4'h5: begin
                    if(vx[ir[11:8]] == vx[ir[7:4]]) begin // skips next instruction if Vx == Vy
                        pc_jump_next_stb <= 1'd1;
                    end
                end
                4'h6: begin
                    vx[ir[11:8]] <= ir[7:0]; // loads constant to Vx
                end
                4'h7: begin
                    vx[ir[11:8]] <= vx[ir[11:8]] + ir[7:0]; // adds constant to Vx; TODO: use ALU
                end
                4'h8: begin // ALU operation
                    vx[ir[11:8]] <= alu_out; 
                    if(alu_vf_we) begin
                        vx[15] <= { 7'd0, alu_carry_or_borrow };
                    end
                end 
                default: useless <= 1;
            endcase
            state <= EXECUTE;
        end 
        EXECUTE: begin
            pc_jump_next_stb <= 1'd0;
            pc_preload_stb <= 1'd0;

            state <= FETCH_1;
        end
        endcase
    end
end

endmodule
