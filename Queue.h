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
		void nextLeg(string city,Team* slowest);
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

void Queue::nextLeg(string city, Team* slowest){
	Queue tempQ = Queue();
	cerr << "Temp queue contents: " << endl;
	tempQ.printQueue();
	cerr << "---End temp Queue--" << endl;
	Team* firstTeam = NULL;
    Team* nextTeam = NULL;
	Team* fastest = NULL;
    //function is still reordering the main queue
	for(int i= size; i > 0; i--){
		cerr << "!!!!!!!!!OUTER FOR BEGIN!!!!!!!!!!" << endl;
		cerr << "First for begin" << endl;
		fastest = pop();
		firstTeam = fastest;						
		cerr << fastest->getName() << " is fastest." << endl;
		if(fastest->getCity() != city){
			fastest->setTime(city);
		}					
		//set its time
		cerr << "Time set." << endl;				
		//Team time set this lap
		int j = size -1;
		while(j > 0){
			cerr << "----------INNER FOR----------" <<endl;	
			//# teams this round
			cerr << "Teams still to run: " << j << endl;
			cerr << "Fastest so far: " << fastest->getName() << endl;
			nextTeam = pop();			
			//next item for comparison
			cerr << nextTeam->getName() << " peeked" << endl;
			if(nextTeam->getCity() != city){		
			//if the team hasn't had a new time generated this lap
				nextTeam->setTime(city);			
				//set a new time
				cerr << "Time set." << endl;
			}
			if(!(fastest->ranFaster(nextTeam))){
				cerr << "Fastest: " << fastest->getName() 
					 << " was slower than " 
					 << "nextTeam: " << nextTeam->getName() << endl;	
				//if fastest is faster than next
				push(fastest);			
				//push the next team back onto the queue
				cerr << "Original now contains prev fastest: " << fastest->getName() << endl;
				fastest = nextTeam;
				j--;
			}
			else if(fastest->ranFaster(nextTeam)){ 
				//if the next team is the fastest
				if(j == 1){
					tempQ.push(fastest);
					cerr << fastest->getName() << " was the fastest team, pushed to the temp queue."  << endl;
					fastest=nextTeam;
					j--;
				}
				else{
					push(nextTeam);
					cerr << nextTeam->getName() << " pushed back into original for being slow." << endl;								
					j--;
				}
			}
		}
	}
	cerr << "Begin copying queues. " << endl;
	Team* slow = NULL;
	while(tempQ.peek() != NULL){	
		//replace the original queue with the fastest times stored in the temp queue
		slow = tempQ.pop();
		if(tempQ.getSize() ==0 ){
			slowest = slow;
		}
		else{
			push(slow);
		}
	}	
}
