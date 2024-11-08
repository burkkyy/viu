CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra
CXXINCLUDES := -I ./include

OBJECT_FILES := build/binary_search_tree.o build/manager.o build/console.o

default: pxe2

build/binary_search_tree.o: src/binary_search_tree.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDES) $^ -o $@

build/manager.o: src/manager.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDES) $^ -o $@

build/console.o: src/console.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDES) $^ -o $@

pxe2: main.cpp $(OBJECT_FILES)
	$(CXX) $(CXXFLAGS) $(CXXINCLUDES) $^ -o $@

.PHONY: clean

clean:
	@-rm -rf build/ 2>/dev/null
	@-rm -rf pxe2 2>/dev/null
