#include"Team.h"

class Queue{
	private: 
		Team* head;
		Team* tail;
		int size;
	public:
		Queue(){ head = tail = NULL; size = 0; }
		void push(Team* n);
		Team* peek();
		Team* pop();
		Team* getTail(){ return tail; }
		Team* getHead(){ return head; }
		int getSize(){ return size; }
		void setTail(Team* n){tail = n;}
		void setHead(Team* n){head = n;}
		void printQueue();
		//string nextLeg(string city);
			//return slowest team name

		Team* nextLeg(string city, int teamsRacing, Team* slowest);
		//Team * fastestTeam(Team* t[], int size);
};

void Queue::push(Team* n){
	if(size == 0){ 
    	head = tail = n;
        head->setNext(tail);
        head->setPrev(NULL);
        tail->setPrev(head);
		tail->setNext(NULL);
    }
    else{   
        n->setNext(NULL);
        n->setPrev(tail);
        tail->setNext(n);
        tail = n; 
    }
    size++;
}

Team* Queue::peek(){
	if(size == 0){
		cout << size << " size" << endl;
    	cout << "\nEmpty queue." << endl;
        return NULL;
    }
    else{
        return head;
    }
}

Team* Queue::pop(){
	Team* temp = head;
    head = temp->getNext();
    size--;
    return temp;
}

void Queue::printQueue(){
    int toPrint = size;
    Team* temp = head;
    while(toPrint > 0){
    	cout << temp->getName() << endl;
        temp = temp->getNext();
        toPrint--;
   	}
}


Team* Queue::nextLeg(string city, int teamsRacing, Team* slowest){
	//cout <<"inside the nextLeg method"<<endl;
	//Team* race = new Team[size]; 
	vector<Team*> race;
	int itemCount = size;
	Team* fastest = new Team();
	Team* next = new Team();
	int tempCount = 0;
	//for(int i = 0; i < itemCount; i++){
	for(int i = 0; i < teamsRacing; i++){
		//cout <<"inside the first for loop"<<endl;
		Team *temp = pop();
		temp->setTime(city);
		race.push_back(temp);
		cout << race[i]->getName() <<endl;
		tempCount++;
	}
	//cout << "After first for" << endl;
	for(int n=0; n < itemCount; n++){
		//cout << race[n]->getName() << " in second for loop" << endl;
		fastest = race[n];
		cout << fastest->getName()<<endl;
		int fastestIndex = n;


		for (int i = n+ 1; i < itemCount; i++){
			if(i < teamsRacing){
				next= race[i];
				//cerr << i << " i value" << endl;
				if(fastest->getTimeInMin() > next->getTimeInMin()){
					fastest = next;
					fastestIndex = i;
				}
			}
		}
		
		if (tempCount > 1){
			push(fastest);
			cerr << "Pushed " << fastest->getName() << endl;
			tempCount--;

		}
		else{
			slowest = fastest;
		}

	}
	//delete fastest;
	//delete next;
	cout << "The slowest is " << slowest->getName()<<endl;

	return slowest;
}
