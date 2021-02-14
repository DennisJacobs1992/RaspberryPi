ouput: main.o
	g++ main.o -lwiringPi -lwiringPiI2C -o output

main.o: main.cpp
	g++ -c main.cpp -lwiringPi -lwiringPiI2C

target: dependencies
	action

clean:
	rm *.o output