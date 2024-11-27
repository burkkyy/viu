`timescale 1ns/1ns
`include "8-bit-adder.v"

module eightBitAdder_tb ();
  reg [7:0] x, y;
  reg ci;
  wire [7:0] s;
  wire co;

  eightBitAdder ut(x, y, ci, s, co);

  initial begin
    $dumpfile("8BitAdder_tb.vcd");
    $dumpvars(0, eightBitAdder_tb);

    ci = 1'b0;

    x = 8'd0;
    y = 8'd0;
      #20;
    x = 8'd1;
    y = 8'd3;
      #20;
    x = 8'd12;
    y = 8'd9;
      #20;
    x = 8'd15;
    y = 8'd123;
      #20;
    x = 8'd243;
    y = 8'd10;
      #20;
    $display("Test complete");
  end
endmodule
