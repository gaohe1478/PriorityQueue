//���1602 �ߺ� 1606070210
#include<iostream>
using namespace std;
#include"UTILITY.H"
#include"PriorityQueue.h"
typedef int data_entry;
#define Queue_num 5//��Ŷ��ٽṹ�����鵽������
void insert(Queue_entry &item);
int main()
{
	PriorityQueue Q;
	Queue_entry E[Queue_num];
	Queue_entry E1[Queue_num];
	//�����鸳ֵ��֮��Ҫ��ӵĶ���
	for(int i=0;i<Queue_num;i++){
		insert(E[i]);
	}
	//���
	for(int j=0;j<Queue_num;j++){
		Q.append(E[j]);
	}
	//�п�
	if(Q.empty()){
		cout<<"��"<<endl;
	}else{
		cout<<"����"<<endl;
	}
	//����retrieve
	Q.retrieve(E1[0]);
	cout<<"E1 data:"<<E1[0].data<<endl;
	cout<<"E1 priority:"<<E1[0].priority<<endl;
	//���Գ���
	for(int k=0;k<Queue_num;k++){
		Q.serve();
	}
	//�п�
	if(Q.empty()){
		cout<<"��"<<endl;
	}else{
		cout<<"����"<<endl;
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