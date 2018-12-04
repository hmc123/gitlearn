#include<iostream>
using namespace std;


class node
{
public:
	int data;
	node *next;
};

class linkqueue
{
public:
	linkqueue()
	{
		front = new node;
		front->next = NULL;
		rear = front;
	}

	node *front, *rear;
};


bool IsEmpty(linkqueue *Q)
{
	if (Q->front == Q->rear)
		return true;
	else
		return false;
}

void EnQueue(linkqueue *Q, int e)
{
	node *p = new node;
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}

int DeQueue(linkqueue *Q)
{
	node *p;
	int k;
	
	if (!IsEmpty(Q))
	{
		p = Q->front;
		k = p->next->data;
		Q->front = p->next;
		delete p;
		return k;  //return the data of the deleted node 
	}
	else
	{
		cout<<"�����ѿգ�";
		return 0;
	}
}

int LenQueue(linkqueue *Q)
{
	int count = 0;
	node *p = Q->front;
	while (p->next != NULL)
	{
		count++;
		p= p->next;
	}
	return count;
}


int main()
{
	linkqueue m;

	cout<<"������н����в���\n";
	for (int i = 0; i<10; i++)
	{
		EnQueue(&m, i*2);
	}

	cout<<"���г���Ϊ��"<<LenQueue(&m)<<endl;

	cout<<"�������������в���\n";
	while (!IsEmpty(&m))
	{
		
		cout<<DeQueue(&m)<<endl;
	}
	cout<<"���г���Ϊ��"<<LenQueue(&m)<<endl;

	return 0;
}