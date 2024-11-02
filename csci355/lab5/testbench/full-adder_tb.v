`timescale 1ns/1ns
`include "full-adder.v"

module fulladder_tb ();
  reg ci, x, y;
  wire f, co;

  fulladder ut(ci, x, y, f, co);

  initial begin
    $dumpfile("fulladder_tb.vcd");
    $dumpvars(0, fulladder_tb);

    ci = 0;
    x = 0;
    y = 0;
      #20;
    ci = 1;
    x = 0;
    y = 0;
      #20;
    ci = 0;
    x = 1;
    y = 0;
      #20;
    ci = 1;
    x = 1;
    y = 0;
      #20;
    ci = 0;
    x = 0;
    y = 1;
      #20;
    ci = 1;
    x = 0;
    y = 1;
      #20;
    ci = 0;
    x = 1;
    y = 1;
      #20;
    ci = 1;
    x = 1;
    y = 1;
      #20;
      
  $display("Test complete");
  end

endmodule
