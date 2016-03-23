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
		Team* nextLeg(string city,int lap);
};

void Queue::push(Team* n){
	if(size == 0){ 
		head = tail = NULL;
    	head = tail = n;
        head->setNext(tail);
        head->setPrev(NULL);
        tail->setPrev(head);
    }
    else{   
        n->setNext(NULL);
        n->setPrev(tail);
        tail->setNext(n);
        setTail(n); 
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

Team* Queue::nextLeg(string city, int lap){
	Queue tempQ = Queue();
	cerr << "Temp queue contents: " << endl;
	tempQ.printQueue();
	cerr << "---End temp Queue--" << endl;
	Team* fastest = pop();
    Team* nextTeam = NULL;
    fastest->setTime(city);	

    //function is still reordering the main queue
	for(int n = size; n > 0; n--){
		cerr << "First for begin" << endl;						//store first as fastest
		cerr << fastest->getName() << " is fastest." << endl;
		//fastest->setTime(city);					//set its time
		cerr << "Time set." << endl;				//Team time set this lap
		for(int i = n-1; i > 0; i--){
			cerr << "----------INNER FOR----------" <<endl;			//# teams this round
			cerr << "Teams still to run: " << i << endl;
			cerr << "Fastest so far: " << fastest->getName() << endl;
			nextTeam = pop();			//next item for comparison
			cerr << nextTeam->getName() << " peeked" << endl;
			if(nextTeam->getCity() != city){		//if the team hasn't had a new time generated this lap
				nextTeam->setTime(city);			//set a new time
				cerr << "Time set." << endl;
			}
			if(fastest->ranFaster(nextTeam)){	//if fastest is fastest
				push(nextTeam);			//push the compared team back onto the queue
				cerr << nextTeam->getName() << " pushed back into original" << endl;
			}
			else if(i == 1){
				tempQ.push(fastest);				//push the fastest onto the temp queue
				cerr << "TempQ now contains " << peek()->getName() << endl;
				cerr << "Teams to sort: " << n << endl;
				cerr << "Teams to sort decremented: " << n << endl;
			}
			else{								//Otherwise,
				push(fastest);					//push the fastest item back onto the queue
				cerr << fastest->getName() << " pushed" << endl;
				fastest = nextTeam;//set the new team as the fastest
				cerr << "New fastest: " << fastest->getName() << endl;
			}
			cerr << "!!!!!!OUTER FOR!!!!!!!" << endl;
		}
		cerr << "Outer for loop end" << endl;
	}cerr << "Out of outer for while" << endl;
	while(tempQ.getSize() > 0){	//replace the original queue with the fastest times stored in the temp queue
		Team* toTransfer = tempQ.peek();
		if(tempQ.getSize() != 1){
			push(tempQ.pop());
		}
		else{
			return toTransfer;
		}
	}	
}
