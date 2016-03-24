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
		Team * fastestTeam(Team* t[], int size);
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
	Team* race = new Team[size];
	int itemCount = size;
	for(int i = 0; i < itemCount; i++){
		cout <<"inside the first for loop"<<endl;
		Team temp = *pop();
		temp.setTime(city);
		race[i] = temp;
	}
	Team *Order = fastestTeam(&race, size);
	for(int i = 0; i < size; i++){
		cout <<"print test" <<endl;
		//push(race[i])	
	} 	
}
Team * Queue::fastestTeam(Team* t[], int size){
	Team** tempArray = new Team*[size];
	Team *fastest =  NULL;
	Team *next = NULL;
	for(int n=0; n < size; n++){
		fastest = t[n];
		for (int i = n + 1; i < size; i ++){
			next= t[i];
			if(fastest->getTimeInMin() < next->getTimeInMin()){
				tempArray[n]= t[n];
			}
			else{
				fastest= t[i];
			}	
		}
		tempArray[n] = fastest;
	}
	return *tempArray;
}

