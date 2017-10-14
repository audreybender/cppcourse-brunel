#include <iostream>
#include <array> 


using namespace std; 

const int MAX = 16; 

class cqueue {
	
	public : 
	
	cqueue() {
		/*for ( auto element : CQ ) {
			element = 0.0; 
		}*/
		front = rear = 0; 
	}
	
	//Getter
	int getFront() const; 
	int getRear() const; 
	
	//Méthode
	void enqueue(double); 
	void dequeue();
	
	array<double, MAX> CQ; 
	
	private : 
	
	int front;
	int rear; 
};

//Getter
int cqueue::getFront() const {
	return front;
}
int cqueue::getRear() const {
	return rear;
}

//Méthodes 
void cqueue::enqueue( double val) {
	
	if ( rear == MAX+1) {
		rear = 0; 
	}else{
		rear++; 
		CQ[rear]=val;  
	}
	
}

void cqueue::dequeue() {
	
	double k(0.0); 
	CQ[front] = k;
	if( front == rear) {
		rear++;
	  }
	front ++;
	if ( front == MAX+1) {
		front = 0;
	}
	if ( rear == MAX+1) {
		rear = 0;
	}

}

