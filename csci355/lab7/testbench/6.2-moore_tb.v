`timescale 1ns/1ns
`include "6.2-moore.v"

module moore62_tb();
  reg clk, reset, w;
  wire z;

  FSM f(clk, reset, w, z);

  always #5 clk = ~clk;

  initial begin
    $dumpfile("moore62_tb.vcd");
    $dumpvars(0, moore62_tb);
    
    clk = 0;
    reset = 1;
    w = 0;

    #10; reset = 0;

    #10; w = 0; // q0 -> q0
    #10; w = 1; // q0 -> q1
    #10; w = 0; // q1 -> q2
    #10; w = 1; // q2 -> q4
    #10; w = 1; // q4 -> q1
    #10; w = 1; // q1 -> q3
    #10; w = 0; // q3 -> q4
    #10; w = 1; // q4 -> q1
    #10; w = 0; // q1 -> q2
    #10; w = 1; // q2 -> q4
    #10; w = 0; // q4 -> q0
    #10; w = 0; // q0 -> q0
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
