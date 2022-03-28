#pragma once
#include<iostream>
using namespace std;
#include"Node.h"
template<class t>
class QueueLinkedChain
{
private:
	Node<t>* rear;
	int count;
public:
	QueueLinkedChain()
	{
		count = 0;
		rear = NULL;
	}
	bool isEmpty()
	{
		return count == 0;
	}
	bool enqueue(t val)
	{
		Node<t>* newnode;
		if (newnode = new Node<t>(val))
		{
			if (count == 0)
			{
				newnode->setNext(newnode);
			}
			else
			{
				newnode->setNext(rear->getNext());
				rear->setNext(newnode);
			}
			rear = newnode;
			count++;
			return true;
		}
		else
			return false;
	}
	bool dequeue()
	{
		if (isEmpty())
			return false;
		count--;
		if (count == 0)
		{
			delete rear;
			rear = NULL;
			return true;
		}
		Node<t>* del = rear->getNext();
		rear->setNext(rear->getNext()->getNext());
		delete del;
		return true;
	}
	void destroy()
	{
		while (!isEmpty())
			dequeue();
	}
	t peekFront()
	{
		return rear->getNext()->getData();
	}
	~QueueLinkedChain()
	{
		destroy();
	}
};

