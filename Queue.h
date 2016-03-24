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
		Team* nextLeg(string city);
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

Team* Queue::nextLeg(string city){
	cout <<"inside the nextLeg method"<<endl;
	//Team* race = new Team[size];
	Team *race [size];
	int itemCount = size;
	Team *fastest =  NULL;
	Team *next = NULL;
	for(int i = 0; i < itemCount; i++){
		cout <<"inside the first for loop"<<endl;
		Team *temp = pop();
		temp->setTime(city);
		race[i] = temp;
		//cout << race[i] <<endl;
		cerr << "race set to temp" << endl;
	}
	for(int n=0; n < size; n++){
		fastest = race[n];
		for (int i = n + 1; i < size; i ++){
			next= race[i];
			if(fastest->getTimeInMin() > next->getTimeInMin()){
				fastest = next;
			}	
		}
		push(fastest);
	}
}

