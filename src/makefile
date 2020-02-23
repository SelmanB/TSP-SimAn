all: route.o main.o
	g++ -O2 -std=c++11 -o tsp route.o main.o
route.o: route.cpp
	g++ -O2 -std=c++11 -c route.cpp
route.cpp: route.h siman.h
	touch route.cpp
main.o: main.cpp siman.h
	g++ -O2 -std=c++11 -c main.cpp

