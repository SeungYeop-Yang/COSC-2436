all: recursion factorial factorial_recursive backward


recursion: recursion.cpp
	g++ -o recursion  recursion.cpp
	
factorial: factorial.cpp
	g++ -o factorial factorial.cpp

factorial_recursive: factorial_recursive.cpp
	g++ -o factorial_recursive factorial_recursive.cpp

backward: backward.cpp
	g++ -o backward backward.cpp

.PHONY: clean
clean: 
	rm -f recursion factorial factorial_recursive backward
