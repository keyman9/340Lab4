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
    Team* fastest = pop();
    fastest->setTime();

    //function is still reordering the main queue
    bool calculating = true;
    do{
    	for(int i = 0; i < size; i++){
        	Team* fromOrig = peek();
            if(fastest->ranFaster(fromOrig)){
            	tempQ.push(pop());
            }
            else{
                push(fastest);
                fastest = pop();
            }
        }
        if(tempQ.getSize() == size - 1)
            calculating = false;
     }while(calculating);
}

