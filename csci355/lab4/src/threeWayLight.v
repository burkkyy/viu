//Structural Specification
module threeWayLight (
    x1,x2,x3,f
);
    input wire x1,x2,x3;
    output wire f;
    wire nx1, nx2, nx3, a1, a2, a3, a4;
    
    not(nx1, x1); // ~x1
    not(nx2, x2); // ~x2
    not(nx3, x3); // ~x3

    and(a1, nx1, nx2, x3);
    and(a2, nx1, x2, nx3);
    and(a3, x1, x2, x3);
    and(a4, x1, nx2, nx3);
    or(f, a1, a2, a3, a4);

    assign o = (~x1 & ~x2 & x3) | (~x1 & x2 & ~x3) | (x1 & x2 & x3) | (x1 & ~x2 & ~x3);

endmodule
