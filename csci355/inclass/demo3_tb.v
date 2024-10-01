`timescale 1ns/1ns
`include "demo3.v"
module demo3_tb (
);
    reg [1:0] count;
    wire f;

    demo3 ut(count[1], count[0],f);

    initial begin
        $dumpfile("demo3_tb.vcd");
        $dumpvars(0, demo3_tb);

        count[1] = 0;
        count[0] = 0;
		#20;
		
        count[1] = 0;
        count[0] = 1;
		#20;
		
        count[1] = 1;
        count[0] = 0;
		#20;
		
        count[1] = 1;
        count[0] = 1;
		#20;
	
		
		$display("Test complete");

    end
  
endmodule