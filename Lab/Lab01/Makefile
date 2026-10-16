CXX = g++
# https://gcc.gnu.org/onlinedocs/gcc-3.4.1/gcc/Warning-Options.html#Warning%20Options
# try to collect all warnings and errors
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
# target executable name
TARGET = lab1_SeungYeop_Yang
SRC = lab1_SeungYeop_Yang.cpp
# don't forget the depedencies for the SRC  
DEPS = $(SRC) ArrayBag.h ArrayBag.cpp BagInterface.h

all: $(TARGET)

$(TARGET): $(DEPS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
