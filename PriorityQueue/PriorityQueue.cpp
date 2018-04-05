#include<iostream>
using namespace std;
#include"PriorityQueue.h"
#include"UTILITY.H"

PriorityQueue::PriorityQueue()
{
	rear=maxqueue-1;
	front=0;
	count=0;
}

bool PriorityQueue::empty() const
{
	return count==0;
}

Error_code  PriorityQueue::serve()
{
	if(count<=0){
		return underflow;
	}else{
		count--;
		cout<<"data:"<<entry[front].data;
		cout<<"priority:"<<entry[front].priority;
		front=((front+1)==maxqueue)?0:(front+1);
		cout<<"队首已经出队！"<<endl;
		return success;
	}
}

Error_code PriorityQueue::append(const Queue_entry &item)
{
	int i;
	i=rear;

	if(count>=maxqueue){
		return overflow;	
	}else{
		if(count==0){
			entry[front].data=item.data;
			entry[front].priority=item.priority;
			count++;
			rear=((rear+1)==maxqueue)?0:(rear+1);
			return success;
		}else{
			count++; 
			while(item.priority>entry[i].priority && i >= 0){
				if((i+1)==maxqueue){
					rear=0;//等于maxqueue就让从0开始赋值
					entry[0].data=entry[i].data;
					entry[0].priority=entry[i].priority;//从后往前比
					i--;
				}else{
					
					entry[i+1].data=entry[i].data;
					entry[i+1].priority=entry[i].priority;
					i--;
				}
			
			}
			rear++;//尾正常加一
			entry[i+1].data=item.data;
			entry[i+1].priority=item.priority;
			return success;
		
		}
		
	}
}

Error_code PriorityQueue::retrieve(Queue_entry &item) const
{
	if(count<=0){
		return underflow;
	}else{
		item.data=entry[front].data;
		item.priority=entry[front].priority;
		return success;
	}

}
