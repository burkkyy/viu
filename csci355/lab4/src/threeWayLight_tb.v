`timescale 1ns/1ns
`include "threeWayLight.v"
module threeWayLight_tb (
);
    reg x1, x2, x3;
    wire f;

    threeWayLight ut(x1, x2, x3, f);

    initial begin
        $dumpfile("threeWayLight_tb.vcd");
        $dumpvars(0, threeWayLight_tb);

        x1 = 0;
        x2 = 0;
	x3 = 0;
		#20;
	x1 = 0;
        x2 = 0;
	x3 = 1;
		#20;
	x1 = 0;
        x2 = 1;
	x3 = 0;
		#20;
	x1 = 0;
        x2 = 1;
	x3 = 1;
		#20;
	x1 = 1;
        x2 = 0;
	x3 = 0;
		#20;
	x1 = 1;
        x2 = 0;
	x3 = 1;
		#20;
	x1 = 1;
        x2 = 1;
	x3 = 0;
		#20;
	x1 = 1;
        x2 = 1;
	x3 = 1;
		#20;

	$display("Test complete");
    end

endmodule
