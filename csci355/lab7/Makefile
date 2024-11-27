CC := iverilog

BUILD := build
TARGETS := 6.1-moore.vvp 6.2-moore.vvp 6.3-mealy.vvp 6.4-mealy.vvp

default: $(TARGETS)

6.1-moore.vvp: testbench/6.1-moore_tb.v
	$(CC) -Isrc $^ -o $(BUILD)/$@

6.2-moore.vvp: testbench/6.2-moore_tb.v
	$(CC) -Isrc $^ -o $(BUILD)/$@

6.3-mealy.vvp: testbench/6.3-mealy_tb.v
	$(CC) -Isrc $^ -o $(BUILD)/$@

6.4-mealy.vvp: testbench/6.4-mealy_tb.v
	$(CC) -Isrc $^ -o $(BUILD)/$@
