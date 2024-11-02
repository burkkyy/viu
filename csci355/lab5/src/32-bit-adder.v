`include "8-bit-adder.v"

// Structural Specification
module thirtyTwoBitAdder (
  input wire[31:0] x, y,
  input wire ci,
  output wire[31:0] s,
  output wire co
);
  wire c[2:0];
  eightBitAdder f0(x[7:0], y[7:0], ci, s[7:0], c[0]);
  eightBitAdder f1(x[15:8], y[15:8], c[0], s[15:8], c[1]);
  eightBitAdder f2(x[23:16], y[23:16], c[1], s[23:16], c[2]);
  eightBitAdder f3(x[31:24], y[31:24], c[2], s[31:24], co);
endmodule
