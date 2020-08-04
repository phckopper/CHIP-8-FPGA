module PC(
    input wire clk,
    input wire rst,
    input wire [11:0] preload,
    input wire preload_stb,
    input wire jump_next_stb,
    input wire inc_stb,

    output reg [11:0] out
);

always @(posedge clk) begin
    if(rst) begin
        out <= 12'd0; // reset
    end else begin
        if(preload_stb) begin
            out <= preload; // preloads PC, probably with the address from a jump instruction
        end else begin
            if(jump_next_stb) begin
                out <= out + 12'd2; // skips next instruction
            end else begin
                if(inc_stb) begin
                    out <= out + 12'd1; // normal incrementing
                end
            end
        end
    end
end


endmodule
