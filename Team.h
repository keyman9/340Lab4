#include<string>
#include<cstdlib>
#include "Time.h"
#include<iostream>
using namespace std;

class Team{
private:
    string name;
	Team* next;
	Team* prev;
	Time* top;
public:
	Team();
	Team(string Name);
	Team(string n, Team* tN, Team* tP, Time* t){ name=n;next=tN;prev=tP;top=t;} 
	~Team(){ delete next; delete prev; delete top; }
	string getName();
	void setTime(string c);
	Time* getTime(){ return top; }
	bool ranFaster(Team* compare);
	string getCity(){ return top->city; }
	Team* getNext(){ return next; }
	void setNext(Team* n){ next = n; }
	Team* getPrev(){ return prev; }
	void setPrev(Team* p){ prev = p; }
	int getTimeInMin(){ return top->timeInMin; }

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
	//cerr <<" inside the set time method"<<endl;
    Time *t = new Time();
    //cerr <<" created the time object t"<<endl;
    t->city = c;
    t->hour = rand() % 23 + 5;
   // cerr << "Hour:\t" << t->hour << endl;
    t->min = rand() % 59 + 0;
   // cerr << "Min:\t" << t->min << endl; 
    t->next = NULL;
    top->next= t;
	t->prev = top;
    top = top->next;
    top->timeInMin = (top->hour*60)+(top->min);
}

Team::Team(){
    name = "";
	next=prev=NULL;
	top = new Time();
}

Team::Team(string Name){
    name = Name;
	top = new Time();
    top->hour=0;
    top->min=0;
    top->next=NULL;
    top->prev=NULL;
}

string Team::getName(){
    return name;
}
