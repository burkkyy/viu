module FSM (
  input wire clk,
  input wire reset,
  input wire w,
  output reg z
);
  parameter q0 = 1'b0, q1 = 1'b1;

  reg[1:0] current_state, next_state;

  always @(posedge clk or posedge reset) begin
    case(current_state)
      q0: begin
        if(w) begin
          z = 1'b0;
          next_state = q1;
        end else begin
          z = 1'b0;
          next_state = q0;
        end
      end
      q1: begin
        if(w) begin
          z = 1'b1;
          next_state = q1;
        end else begin
          z = 1'b0;
          next_state = q0;
        end
      end
      
      default: begin 
        z = 1'b0;
        next_state = q0;
      end
    endcase

    if(reset) begin
      current_state = q0;
      next_state = q0;
    end
    else 
      current_state = next_state;
  end
endmodule
