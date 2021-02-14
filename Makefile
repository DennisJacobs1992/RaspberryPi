ouput: main.o
	g++ main.o -o ouput

main.o: main.cpp
	g++ -c main.cpp -lwiringPi

target: dependencies
	action

clean:
	rm *.o ouput