`timescale 1ns/1ns
`include "32-bit-adder.v"

module thirtyTwoBitAdder_tb ();
  reg[31:0] x, y;
  wire ci;
  wire[31:0] f;
  wire co;

  thirtyTwoBitAdder ut(x, y, ci, f, co);

  initial begin
    $dumpfile("32BitAdder_tb.vcd");
    $dumpvars(0, thirtyTwoBitAdder_tb);

    x = 0;
    y = 0;
      #20;

  $display("Test complete");
  end

endmodule
