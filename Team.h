#include<string>
#include<cstdlib>
#include "Time.h"

using namespace std;

class Team{
private:
    string name;
	bool lapTimed;
	Team* next;
	Team* prev;
	Time* top;
public:
	Team();
	Team(string Name);
	~Team(){ delete next; delete prev; delete top; }
	string getName();
	bool getLapTimed(){ return lapTimed; }
	void lapToggle(){ lapTimed = !lapTimed; }
	void setTime(string c);
	Time* getTime(){ return top; }
	bool ranFaster(Team* compare);
	string getCity(){ return top->city; }
	Team* getNext(){ return next; }
	void setNext(Team* n){ next = n; }
	Team* getPrev(){ return prev; }
	void setPrev(Team* p){ prev = p; }
};

bool Team::ranFaster(Team* compare){
	if(top->hour > compare->getTime()->hour){
		return false;
	}
	else if (top->hour == compare->getTime()->hour){
		if(top->min > compare->getTime()->min){
			return false;
		}
		else{
			return true;
		}
	}
	else{
		return true;
	}
}
void Team::setTime(string c){
    Time *t = new Time();
    t->city = c;
    t->hour = rand() % 23 + 5;
    cout << "Hour:\t" << t->hour << endl;
    t->min = rand() % 59 + 0;
    cout << "Min:\t" << t->min << endl; 
    t->next = NULL;
    top->next= t;
	t->prev = top;
    top = top->next;
}

Team::Team(){
    name = "";
	next=prev=NULL;
	lapTimed = false;
	top = new Time();
}

Team::Team(string Name){
    name = Name;
	lapTimed = false;
	top = new Time();
    top->hour=0;
    top->min=0;
    top->next=NULL;
    top->prev=NULL;
}

string Team::getName(){
    return name;
}
