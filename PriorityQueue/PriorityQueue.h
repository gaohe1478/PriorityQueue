#include<iostream>
#include"UTILITY.H"
typedef int data_entry;
struct Queue_entry{
	data_entry data;
	int priority;
};

const int maxqueue = 50; // small value for testing

class PriorityQueue {
	public:
		PriorityQueue();
		bool empty() const;
		Error_code serve();
		Error_code append(const Queue_entry &item);
		Error_code retrieve(Queue_entry &item) const;
	protected:
		int rear;
		int front;
		int count;
		Queue_entry entry[maxqueue];
};
