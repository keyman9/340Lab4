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
		void nextLeg();
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

void Queue::nextLeg(){
	Queue tempQ = Queue();
    Team* fastest = NULL;
	int teamsToSort = size;
	int itemsInQueue;
    //function is still reordering the main queue
	do{
		cerr << "Do while loop beg" << endl;	
		fastest = pop();					//store first as fastest
		fastest->setTime();					//set its time
		fastest->lapToggle();				//Team time set this lap
		itemsInQueue = size;			//# teams this round
		if(peek() == NULL){
			break;
		}
		else{
			Team* nextTeam = peek();			//next item for comparison
			if(!(nextTeam->getLapTimed()))		//if the team hasn't had a new time generated this lap
				nextTeam->setTime();			//set a new time
				nextTeam->lapToggle();			//flip the toggle
			if(fastest->ranFaster(nextTeam)){	//if fastest is fastest
				push(nextTeam);					//push the compared team back onto the queue
			}
			else{								//Otherwise,
				push(fastest);					//push the fastest item back onto the queue
				fastest = nextTeam;				//set the new team as the fastest
			}
			if(itemsInQueue == teamsToSort - 1){	//if there are no more teams to compare this fastest with
				tempQ.push(fastest);				//push the fastest onto the temp queue
				teamsToSort--;						//there is one less team to sort now
			}
			cerr << "End else" << endl;
		}
		cerr << "Do while loop end" << endl;
	}while(teamsToSort > 0);					//as long as there are teams to sort
	cerr << "Out of while" << endl;
	while(tempQ.peek() != NULL){	//replace the original queue with the fastest times stored in the temp queue
		Team* toOrig = tempQ.pop();
		push(toOrig);
	}
	cerr << "Bottom" << endl;	
}
