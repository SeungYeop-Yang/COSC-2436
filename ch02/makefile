all: recursion factorial factorial_recursive


recursion: recursion.cpp
	g++ -o recursion  recursion.cpp
	
factorial: factorial.cpp
	g++ -o factorial factorial.cpp

factorial_recursive: factorial_recursive.cpp
	g++ -o factorial_recursive factorial_recursive.cpp

.PHONY: cleanall
cleanall: 
	rm -f recursion factorial factorial_recursive
