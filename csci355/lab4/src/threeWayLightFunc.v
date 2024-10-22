//Structural Specification
module threeWayLightFunc (
    x1,x2,x3,f
);
    input wire x1,x2,x3;
    output wire f;
    assign f = (~x1 & ~x2 & x3) | (~x1 & x2 & ~x3) | (x1 & x2 & x3) | (x1 & ~x2 & ~x3);
endmodule
