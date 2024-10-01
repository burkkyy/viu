//Structural Specification
module demo1 (
    x1,x2,f
);
    input x1,x2;
    output f;
    wire c;

    not (c,x2);
    and (f,x1,c);

endmodule