#include <string>
#include <stdlib.h>
#include "Time.h"

using namespace std;

class Team{
private:
    string name;
	Team* next;
	Team* prev;
public:
	Team();
	Team(string Name);
	string getName();
	Time* top;
	void setTime();
	Time* getTime(){ return top; }
	Team* getNext(){ return next; }
	void setNext(Team* n){ next = n; }
	Team* getPrev(){ return prev; }
	void setPrev(Team* p){ prev = p; }
};

void Team::setTime(){
    Time *t;
    t->hour = rand() % 23 + 5;
    t->min = rand() % 59 + 0;
    t->next = NULL;
    top->next= t;
	t->prev = top;
    top = top->next;
}

Team::Team(){
    name = "";
	next=prev=NULL;
	top =  new Time;
}

Team::Team(string Name){
    name = Name;
	top = new Time;
    top->hour=00;
    top->min=00;
    top->next=NULL;
    top->prev=NULL;
}

string Team::getName(){
    return name;
}
