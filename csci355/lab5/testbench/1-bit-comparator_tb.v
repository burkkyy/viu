`timescale 1ns/1ns
`include "1-bit-comparator.v"

module oneBitComparator_tb ();
  reg eq_in, gt_in, lt_in, a, b;
  wire eq, gt, lt;

  oneBitComparator ut(eq_in, gt_in, lt_in, a, b, eq, gt, lt);

  initial begin
    $dumpfile("1BitComparator_tb.vcd");
    $dumpvars(0, oneBitComparator_tb);

    eq_in = 0;
    gt_in = 0;
    lt_in = 0;
    a = 0;
    b = 0;
      #20;
    eq_in = 0;
    gt_in = 0;
    lt_in = 0;
    a = 0;
    b = 0;
      #20;

  $display("Test complete");
  end

endmodule
