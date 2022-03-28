#pragma once
#include<iostream>
using namespace std;
#include"Node.h"
template<class t>
class QueueLinkedList
{
private:
	Node<t>* front;
	Node<t>* rear;
	int count;
public:
	QueueLinkedList()
	{
		count = 0;
		front = NULL;
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
				front = newnode;
			}
			else
			{
				rear->setNext(newnode);
			}
			newnode->setNext(NULL);
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
		count -- ;
		if (count == 0)
		{
			delete front;
			front = NULL;
			rear = NULL;
			return true;
		}
		Node<t>* del = front;
		front = front->getNext();
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
		return front->getData();
	}
	~QueueLinkedList()
	{
		destroy();
	}
};

