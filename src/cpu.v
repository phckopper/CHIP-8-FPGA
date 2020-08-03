module CPU(
    input wire clk,
);

reg [15:0] ir;
reg [7:0] i;
reg [11:0] pc;
reg [7:0] vx [0:15];
reg [7:0] memory [0:4095];
reg [7:0] mem_in;
reg [7:0] mem_out;
reg mem_we;

localparam PREPARE, FETCH_1, FETCH_2, DECODE, EXECUTE;
reg [3:0] state;

always @(posedge clk) begin
    if(mem_we) begin
        memory[mem_addr] <= mem_in;
    end 
    else begin
        mem_out <= memory[mem_addr];
    end
end

always @(posedge clk) begin
    case(state)
        PREPARE:
            mem_addr <= pc;
            mem_we <= 0;
            state <= FETCH_1;
        FETCH_1:
            ir[15:8] <= mem_out;
            mem_addr <= pc + 12'1;
            pc <= pc + 12'1;
            state <= FETCH_2;
        FETCH_2:
            ir[7:0] <= mem_out;
            pc <= pc + 12'1;
            state <= DECODE;
        DECODE:
            case(ir)
                
            endcase 
        
        EXECUTE:
    endcase
end

endmodule
