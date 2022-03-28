#pragma once
#include<iostream>
#include"Node.h"
using namespace std;
template<class t>
class CircularLinkedList
{
	Node<t>* head;
public:
	CircularLinkedList()
	{
		head = NULL;
	}
	bool isEmpty()
	{
		return head == NULL;
	}
	void insertFirst(t val)
	{
		Node<t>* newNode = new Node<t>;
		newNode->setData(val);
		//if there are no nodes yet
		if (isEmpty()) {
			head = newNode;
			newNode->setNext(head);
		}
		else
		{
			Node<t>* tmp;
			for (tmp = head; tmp->getNext() != head; tmp = tmp->getNext());
			newNode->setNext(head);
			head = newNode;
			tmp->setNext(head);
		}
	}
	void insertLast(t val)
	{
		Node<t>* newNode = new Node<t>;
		newNode->setData(val);
		//if there are no nodes yet
		if (isEmpty())
		{
			head = newNode;
			newNode->setNext(head);
		}
		else
		{
			Node<t>* tmp;
			for (tmp = head; tmp->getNext() != head; tmp = tmp->getNext())
			{

			}
			tmp->setNext(newNode);
			newNode->setNext(head);
		}
	}
	void display()
	{
		if (!isEmpty())
		{
			Node<t>* tmp = head;
			cout << tmp->getData();
			if (tmp->getNext() != head)
				cout << "-->";
			for (tmp = head->getNext(); tmp != head; tmp = tmp->getNext()) {
				cout << tmp->getData();
				if (tmp->getNext() != head)
					cout << "-->";
			}
			cout << endl;
		}
	}
	int count()
	{
		if (isEmpty())
			return 0;
		int n = 1;
		for (Node<t>* tmp = head->getNext(); tmp != head; tmp = tmp->getNext())
			n++;
		return n;
	}
	bool exists(t val)
	{
		if (isEmpty())
			return false;
		Node<t>* tmp = head;
		if (tmp->getData() == val) return true;
		for (tmp = head->getNext(); tmp != head; tmp = tmp->getNext())
		{
			if (tmp->getData() == val)
				return true;
		}
		return false;
	}
	bool del(t val)
	{
		if (!exists(val))
			return false;
		else
		{
			Node<t>* tmp,*del;
			if (head->getData() == val)
			{
				for (tmp = head; tmp->getNext() != head; tmp = tmp->getNext());
				del = head;
				head = head->getNext();
				del = NULL;
				delete del;
				if (head)
					tmp->setNext(head);
			}
			else
			{
				for (tmp = head; tmp->getNext()->getData() != val; tmp = tmp->getNext());
				del = tmp->getNext();
				tmp->setNext(tmp->getNext()->getNext());
				delete del;
			}
		}
		return true;
	}
	Node<t>* getHead()
	{
		return head;
	}
};

