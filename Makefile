all: lab4
	

lab4: lab4.cpp Queue.h Team.h Time.h
	g++ lab4.cpp -o lab4

clean:
	$(RM) lab4

