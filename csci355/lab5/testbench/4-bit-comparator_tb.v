`timescale 1ns/1ns
`include "4-bit-comparator.v"

module fourBitComparator_tb ();
  reg[3:0] a, b;
  wire eq, gt, lt;

  fourBitComparator ut(a, b, eq, gt, lt);

  initial begin
    $dumpfile("4BitComparator_tb.vcd");
    $dumpvars(0, fourBitComparator_tb);

    a = 4'b0000;
    b = 4'b0000;
      #20;
    a = 4'b1101;
    b = 4'b0010;
      #20;
    a = 4'b0100;
    b = 4'b0111;
      #20;
    a = 4'b0001;
    b = 4'b1111;
      #20;
    a = 4'b1111;
    b = 4'b0000;
      #20;
    a = 4'b1111;
    b = 4'b1111;
      #20;

  $display("Test complete");
  end

endmodule
