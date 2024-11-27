`timescale 1ns/1ns
`include "32-bit-adder.v"

module thirtyTwoBitAdder_tb ();
  reg[31:0] x, y;
  reg ci;
  wire[31:0] f;
  wire co;

  thirtyTwoBitAdder ut(x, y, ci, f, co);

  initial begin
    $dumpfile("32BitAdder_tb.vcd");
    $dumpvars(0, thirtyTwoBitAdder_tb);

    ci = 1'b0;

    x = 32'd0;
    y = 32'd0;
      #20;
    x = 32'd124;
    y = 32'd1441;
      #20;
    x = 32'd412412;
    y = 32'd90809;
      #20;
    x = 32'd4294967295;
    y = 32'd0;
      #20;
    x = 32'd4294967295;
    y = 32'd1;
      #20;

  $display("Test complete");
  end

endmodule
