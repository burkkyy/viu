`include "1-bit-comparator.v"

// Structural Specification
module fourBitComparator (
  input wire[3:0] a,
  input wire[3:0] b,
  output wire equal,
  output wire greaterThan,
  output wire lessThan
);
  wire eq_3, gt_3, lt_3;
  wire eq_2, gt_2, lt_2;
  wire eq_1, gt_1, lt_1;

  oneBitComparator f3(1, 0, 0, a[3], b[3], eq_3, gt_3, lt_3);
  oneBitComparator f2(eq_3, gt_3, lt_3, a[2], b[2], eq_2, gt_2, lt_2);
  oneBitComparator f1(eq_2, gt_2, lt_2, a[1], b[1], eq_1, gt_1, lt_1);
  oneBitComparator f0(eq_1, gt_1, lt_1, a[0], b[0], equal, greaterThan, lessThan);
endmodule
