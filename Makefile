output: lab4.o
	g++ lab4.o -o output

lab4: lab4.cpp
	g++ -c lab4.cpp

clean:
	rm *.o output

