module FSM (
  input wire clk,
  input wire reset,
  input wire w,
  output reg z
);
  parameter q0 = 3'b000, q1 = 3'b001, q2 = 3'b010, q3 = 3'b011, q4 = 3'b100, q5 = 3'b101;

  reg[2:0] current_state, next_state;

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
          next_state = q1;
        else
          next_state = q0;
      end
      q1: begin
        z = 1'b0;
        if(w)
          next_state = q3;
        else
          next_state = q2;
      end
      q2: begin
        z = 1'b0;
        if(w)
          next_state = q5;
        else
          next_state = q0;
      end
      q3: begin
        z = 1'b0;
        if(w)
          next_state = q3;
        else
          next_state = q4;
      end
      q4: begin
        z = 1'b1;
        if(w)
          next_state = q5;
        else
          next_state = q0;
      end
      q5: begin
        z = 1'b1;
        if(w)
          next_state = q3;
        else
          next_state = q2;
      end
      default: begin
        z = 1'b0;
        next_state = q0;
      end
    endcase
  end

endmodule
