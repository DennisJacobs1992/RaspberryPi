ouput: main.o
	g++ a.out.o -o MakefileOuput

main.o: main.cpp
	g++ main.cpp -lwiringPi

target: dependencies
	action

clean:
	rm *.o MakefileOuput