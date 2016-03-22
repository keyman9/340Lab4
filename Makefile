all: lab4
	

lab4: lab4.cpp
	g++ lab4.cpp -o lab4

clean:
	$(RM) lab4

