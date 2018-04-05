//软件1602 高鹤 1606070210
#include<iostream>
using namespace std;
#include"UTILITY.H"
#include"PriorityQueue.h"
typedef int data_entry;
#define Queue_num 5//想放多少结构体数组到队列中
void insert(Queue_entry &item);
int main()
{
	PriorityQueue Q;
	Queue_entry E[Queue_num];
	Queue_entry E1[Queue_num];
	//给数组赋值（之后要入队的对象）
	for(int i=0;i<Queue_num;i++){
		insert(E[i]);
	}
	//入队
	for(int j=0;j<Queue_num;j++){
		Q.append(E[j]);
	}
	//判空
	if(Q.empty()){
		cout<<"空"<<endl;
	}else{
		cout<<"不空"<<endl;
	}
	//测试retrieve
	Q.retrieve(E1[0]);
	cout<<"E1 data:"<<E1[0].data<<endl;
	cout<<"E1 priority:"<<E1[0].priority<<endl;
	//测试出队
	for(int k=0;k<Queue_num;k++){
		Q.serve();
	}
	//判空
	if(Q.empty()){
		cout<<"空"<<endl;
	}else{
		cout<<"不空"<<endl;
	}
	return 0;
	


}
void insert(Queue_entry &item)
{
	int x,y;
	cout<<"cin data:";
	cin>>x;
	cout<<"cin priority:";
	cin>>y;
	item.data=x;
	item.priority=y;
}