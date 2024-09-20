include config.mk

CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra
CXXINCLUDES := -I ./include

SOURCE_FILES := $(wildcard src/*.cpp)
HEADER_FILES := $(wildcard include/*.hpp)
OBJECT_FILES := $(patsubst %.cpp,build/%.o,$(notdir $(SOURCE_FILES)))

default: all

$(OBJECT_FILES): $(SOURCE_FILES) $(HEADER_FILES)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CXXINCLUDES) -c $(patsubst %.o,src/%.cpp,$(notdir $@)) -o $@

$(TARGET): main.cpp $(OBJECT_FILES)
	$(CXX) $(CXXFLAGS) $(CXXINCLUDES) $^ -o $@

.PHONY: all clean
all: $(TARGET)

clean:
	@-rm -rf build/ 2>/dev/null
	@-rm *.bin 2>/dev/null
	@-rm $(TARGET) 2>/dev/null

