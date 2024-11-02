// Structural Specification
module oneBitComparator (
  input wire eq_in,
  input wire gt_in,
  input wire lt_in,
  input wire a,
  input wire b,
  output wire eq,
  output wire gt,
  output wire lt
);
  assign eq = eq_in & (a == b);
  assign gt = gt_in || (a > b && eq_in);
  assign lt = lt_in || (a < b && eq_in);
endmodule
