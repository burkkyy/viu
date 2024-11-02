CC := iverilog

BUILD := build
TARGETS := full-adder.vvp 8-bit-adder.vvp 32-bit-adder.vvp 1-bit-comparator.vvp 4-bit-comparator.vvp

default: $(TARGETS)

full-adder.vvp: testbench/full-adder_tb.v
	$(CC) -Isrc $^ -o $(BUILD)/$@

8-bit-adder.vvp: testbench/8-bit-adder_tb.v
	$(CC) -Isrc $^ -o $(BUILD)/$@

32-bit-adder.vvp: testbench/32-bit-adder_tb.v
	$(CC) -Isrc $^ -o $(BUILD)/$@

1-bit-comparator.vvp: testbench/1-bit-comparator_tb.v
	$(CC) -Isrc $^ -o $(BUILD)/$@

4-bit-comparator.vvp: testbench/4-bit-comparator_tb.v
	$(CC) -Isrc $^ -o $(BUILD)/$@
