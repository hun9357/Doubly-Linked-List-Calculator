#include<iostream>

using namespace std;

class cal
{
private:
	class node
	{
	public:
		double data;
		node*next;
		node*prev;
		node(double x)
		{
			data = x;
			next = nullptr;
			prev = nullptr;
		}
		
	};
	node*head;
	node*tail;
public:
	double num;
	cal()
	{
		num = 0;
		node*first = new node(num);
		head = first;
		tail = first;
	}
	cal(double x)
	{
		node*baby = new node(x);
		head = baby;
		tail = baby;
		
	}
	void add(double x)
	{
		node*add = new node(x);
		add->data = x;
		add->prev = tail;
		tail->next = add;
		tail = add;
		tail->data += add->prev->data;
			
	}
	void sub(double x)
	{
		node*add = new node(x);
		add->data = x;
		add->prev = tail;
		tail->next = add;
		tail = add;
		tail->data = add->prev->data-tail->data;
	}
	void mult(double x)
	{
		node*div = new node(x);
		div->data = x;
		div->prev = tail;
		tail->next = div;
		tail = div;
		tail->data = div->prev->data * tail->data;
	}
	void divide(double x)
	{
		node*div = new node(x);
		div->data = x;
		div->prev = tail;
		tail->next = div;
		tail = div;
		tail->data = div->prev->data/tail->data;
	}
	void clear()
	{
		node*clear = new node(0);
		tail->next = clear;
		clear->prev = tail;
		tail = clear;
	}
	void display()
	{
		cout << tail->data << endl;
	}
	cal operator+(cal&a)
	{
		cal cal1;
		cal1.tail->data = tail->data + a.tail->data;
		return cal1.tail->data;
	}
	void undo()
	{
		tail = tail->prev;
	}
	void redo()
	{
		tail = tail->next;
	}



};

int main()
{
	cal mycal;
	mycal.add(4.52);
	mycal.add(3.789);
	mycal.divide(2.6);
	mycal.mult(3.12);
	mycal.sub(2.678);
	mycal.display();
	mycal.clear();
	mycal.add(5.0);
	mycal.display();
	cal cal1;
	cal cal2(5.0);
	cal cal3(7);
	cal1 = cal2 + cal3;
	cal1.display();
	mycal.undo();
	mycal.undo();
	mycal.display();
	mycal.redo();
	mycal.redo();
	mycal.display();

	return 0;
}