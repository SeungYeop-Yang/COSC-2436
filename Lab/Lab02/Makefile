CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = lab2_SeungYeop_Yang
SRC = lab2_SeungYeop_Yang.cpp
DEPS = $(SRC) LinkedStack.h LinkedStack.cpp Node.h Node.cpp StackInterface.h

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(DEPS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
