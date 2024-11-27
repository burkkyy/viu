`timescale 1ns/1ns
`include "6.4-mealy.v"

module mealy64_tb();
  reg clk, reset, w;
  wire z;

  FSM f(clk, reset, w, z);

  always #5 clk = ~clk;

  initial begin
    $dumpfile("mealy64_tb.vcd");
    $dumpvars(0, mealy64_tb);
    
    clk = 0;
    reset = 1;
    w = 0;

    #10; reset = 0;

    #10; w = 0;
    #10; w = 1;
    #10; w = 0;
    #10; w = 1;
    #10; w = 1;
    #10; w = 1;
    #10; w = 0;
    #10; w = 1;
    #10; w = 0;
    #10; w = 1;
    #10; w = 0;
    #10; w = 0;
    #10; w = 1;
    #10; w = 0;
    #10; w = 1;
    #10; w = 1;
    #10; w = 0;
    #10; w = 0;

    $finish;
    $display("Test complete");
  end
endmodule
