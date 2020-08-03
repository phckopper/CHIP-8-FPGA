module ALU(
    input [7:0] a,
    input [7:0] b,
    input [3:0] op,
    output [7:0] out,
    output vf_wr, // Should the CPU update VF register?
    output carry_or_borrow, // Shared flag for carry and borrow 
)

// Taken from Chip-8 opcodes table for easy decoding
localparam LD  = 0;
localparam OR  = 1;
localparam AND = 2;
localparam XOR = 3;
localparam ADD = 4;
localparam SUB = 5;
localparam SHR = 6;
localparam RSB = 7;
localparam SHL = 14;

always @(*) begin
    case(op)
        LD:  out = b;
        OR:  out = a | b;
        AND: out = a & b; 
        XOR: out = a ^ b;
        ADD: { carry_or_borrow, out } = a + b;
        SUB: begin
            carry_or_borrow = (a > b); // borrow is inverted
            out = a + ~b + 1;
        end
        SHR: begin
            out = a >> 1;
            carry_or_borrow = a[0];
        end
        RSB: begin
            carry_or_borrow = (b > a); // borrow is inverted
            out = ~a + b + 1;
        end
        SHL: begin
            out = a << 1;
            carry_or_borrow = a[7];
        end
        default: out = 0;
    endcase
end

assign vf_wr = op > XOR: // every op after XOR modifies VF 

endmodule
