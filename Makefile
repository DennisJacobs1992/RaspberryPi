ouput: main.o
	g++ main.o -lwiringPi -pthread -o output

main.o: main.cpp
	g++ -c main.cpp -lwiringPi

target: dependencies
	action

clean:
	rm *.o output