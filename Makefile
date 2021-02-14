ouput: main.o
	g++ main.o -o MakefileOuput

main.o: main.cpp
	g++ main.cpp -lwiringPi

target: dependencies
	action

clean:
	rm *.o MakefileOuput