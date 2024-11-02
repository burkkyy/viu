`timescale 1ns/1ns
`include "8-bit-adder.v"

module eightBitAdder_tb ();
  reg [7:0] x, y;
  wire ci;
  wire [7:0] s;
  wire co;

  eightBitAdder ut(x, y, ci, s, co);

  initial begin
    $dumpfile("8BitAdder_tb.vcd");
    $dumpvars(0, eightBitAdder_tb);

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
