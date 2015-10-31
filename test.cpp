#include <iostream>
using namespace std;


const int maxsize = 20;
class node
{
public:
	node()
	{
		top = -1;
	}
	int data[maxsize];
	int top;
protected:
private:
};

bool IsEmputy(node *s)
{
	if (s->top < 0)
		return true;
	else
		return false;
}

bool IsFull(node *s)
{
	if (s->top > maxsize-1)
		return true;
	else
		return false;
}

int pop(node *s)
{
	if (IsEmputy(s))
		return -1;
	else
	{
		s->top--;
		return s->data[s->top+1];
	}
}

bool push(node *s, int e)
{
	if (IsFull(s))
		return false;
	else
	{
		s->top++;
		s->data[s->top] = e;
		return true;
	}
}

void Convert10tox(int a, int b)
{
	node s;
	int x;
	while(a/b != 0)
	{
		push(&s, a%b);
		a = a/b;
	}
	push(&s, a%b);

	while(!IsEmputy(&s))
	{
		
		x = pop(&s);
		if (x<10)
			cout<<x;
		else if(x==10)
			cout<<'A';
		else if(x==11)
			cout<<'B';
		else if(x==12)
			cout<<'C';
		else if(x==13)
			cout<<'D';
		else if(x==14)
			cout<<'E';
		else
			cout<<'F';
	}
	cout<<'\n';
}

int main()
{
	Convert10tox(2333,9);
	//第四次修改了
	return 0;
}