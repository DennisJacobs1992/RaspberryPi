ouput: main.o
	g++ main.o -lwiringPi -o ouput

main.o: main.cpp
	g++ -c main.cpp -lwiringPi

target: dependencies
	action

clean:
	rm *.o ouput