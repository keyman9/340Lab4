#include"Team.cpp"
#include<iostream>

using namespace std;

class Queue{
	private: 
		Team* head;
		Team* tail;
		int size;
	public:
		Queue(){ head = tail = NULL; size = 0; }
		void push(Team* n){
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
		Team* peek(){
			if(size == 0){
				cout << "\nEmpty queue." << endl;
				return NULL;
			}
			else{
				return head;
			}
		} 
		Team* pop(){
			Team* temp = head;
			head = temp->getNext();
			size--;
			return temp;
		}
		Team* getTail(){ return tail; }
		Team* getHead(){ return head; }
		int getSize(){ return size; }
		void setTail(Team* n){tail = n;}
		void setHead(Team* n){head = n;}
		void printQueue(){
			int toPrint = size;
			Team* temp = head;
			while(toPrint > 0){
				cout << temp->getName() << endl;
				temp = temp->getNext();
				toPrint--;
			}
		}
		void nextLeg(){
			//empty the queue
			//for each item in the array
			//	random the time (setTime())
			//		
			//
			//push onto queue based on difference in time with [0] 
		}
};
