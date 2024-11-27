module FSM (
  input wire clk,
  input wire reset,
  input wire w,
  output reg z
);
  parameter q0 = 2'b00, q1 = 2'b01, q2 = 2'b10, q3 = 2'b11;

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
          z = 1'b0;
          next_state = q3;
        end else begin
          z = 1'b0;
          next_state = q2;
        end
      end
      q2: begin
        if(w) begin
          z = 1'b1;
          next_state = q1;
        end else begin
          z = 1'b0;
          next_state = q0;
        end
      end
      q3: begin
        if(w) begin
          z = 1'b0;
          next_state = q3;
        end else begin
          z = 1'b1;
          next_state = q2;
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
