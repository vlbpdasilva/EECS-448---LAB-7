EECS448_lab7 : Main.o Tester.o
	g++ -g -std=c++11 Main.o Tester.o -o EECS448_lab7
Main.o : Main.cpp LinkedList.h LinkedList.hpp Node.h Node.hpp
	g++ -g -std=c++11 -c Main.cpp
Tester.o : Tester.cpp
	g++ -g -std=c++11 -c Tester.cpp