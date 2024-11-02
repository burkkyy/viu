`include "full-adder.v"

// Structural Specification
module eightBitAdder (
  input wire[7:0] x, y,
  input wire ci,
  output wire[7:0] s,
  output wire co
);
  wire c[6:0];
  fulladder f0(ci, x[0], y[0], s[0], c[0]);
  fulladder f1(c[0], x[1], y[1], s[1], c[1]);
  fulladder f2(c[1], x[2], y[2], s[2], c[2]);
  fulladder f3(c[2], x[3], y[3], s[3], c[3]);
  fulladder f4(c[3], x[4], y[4], s[4], c[4]);
  fulladder f5(c[4], x[5], y[5], s[5], c[5]);
  fulladder f6(c[5], x[6], y[6], s[6], c[6]);
  fulladder f7(c[6], x[7], y[7], s[7], co);
endmodule
