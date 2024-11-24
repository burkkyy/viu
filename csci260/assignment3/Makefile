CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra
CXXINCLUDES := -I ./include

OBJECT_FILES := build/graph.o build/analyzer.o

default: pxe3

build/graph.o: src/graph.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDES) $^ -o $@

build/analyzer.o: src/analyzer.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDES) $^ -o $@

build/manager.o: src/manager.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDES) $^ -o $@

build/console.o: src/console.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDES) $^ -o $@

pxe3: main.cpp $(OBJECT_FILES)
	$(CXX) $(CXXFLAGS) $(CXXINCLUDES) $^ -o $@

.PHONY: clean

clean:
	@-rm -rf build/ 2>/dev/null
	@-rm -rf pxe3 2>/dev/null
