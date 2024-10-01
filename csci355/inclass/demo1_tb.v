`timescale 1ns/1ns
`include "demo1.v"
module demo1_tb (
);
    // reg clk;
    reg [1:0] count;
    wire f;

    demo1 ut(count[1], count[0],f);

    initial begin
        $dumpfile("demo1_tb.vcd");
        $dumpvars(0, demo1_tb);

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

        // clk = 1;
        // count = -1;
    end

    // always #3 clk = ~clk;

    // always @(posedge clk ) begin
    //     count = count + 1;
    
    // end

endmodule