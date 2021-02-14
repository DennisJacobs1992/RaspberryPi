ouput: main.o
	g++ main.o -o MakefileOuput

main.o: main.cpp
	g++ -c main.cpp

target: dependencies
	action

clean:
	rm *.o MakefileOuput