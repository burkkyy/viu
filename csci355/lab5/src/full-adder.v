// Structural Specification
module fulladder (
  input wire ci, xi, yi,
  output wire so, co
);
  and(a1, xi, yi);
  xor(a2, xi, yi);

  and(b1, a2, ci);
  
  xor(so, a2, ci);
  or(co, a1, b1);
endmodule
