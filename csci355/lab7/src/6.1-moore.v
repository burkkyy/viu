module FSM (
  input wire clk,
  input wire reset,
  input wire w,
  output reg z
);
  parameter q0 = 2'b00, q1 = 2'b01, q2 = 2'b10;

  reg[1:0] current_state, next_state;

  always @(posedge clk or posedge reset) begin
    if(reset) begin
      current_state = q0;
      next_state = q0;
    end
    else 
      current_state = next_state;

    case(current_state)
      q0: begin
        z = 1'b0;
        if(w)
          next_state = 2'b01;
      end
      q1: begin
        z = 1'b0;
        if(w)
          next_state = 2'b10;
        else
          next_state = 2'b00;
      end
      q2: begin
        z = 1'b1;
        if(! w)
          next_state = 2'b00;
      end
    endcase
  end

endmodule
