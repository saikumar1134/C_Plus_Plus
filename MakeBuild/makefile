main: main.o display.o
	g++ main.o display.o -o main
	
main.o: main.cpp
	g++ -c main.cpp
	
display.o: display.cpp display.h
	g++ -c display.cpp
	
clean:
	rm *.o main