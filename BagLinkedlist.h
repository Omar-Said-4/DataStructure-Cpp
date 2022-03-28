#pragma once
#include"LinkedList.h"
#include"Bag.h"
template<class t>
class BagLinkedlist :public Bag<t>
{
	LinkedList<t>items;
	int count;
	
	Node<t>* getFirstPointer(const t& val, Node<t>*hd)const
	{
		if (hd == NULL)
			return NULL;
		else if (hd->getData() == val)
		{
			return hd;
		}
		return getFirstPointer(val, hd->getNext());
	}
	
public:
	BagLinkedlist()
	{
		count = 0;
	}
	int getCurrentSize() const
	{
		return count;
	}
	bool isEmpty()const
	{
		return count == 0;
	}
	bool add(const t& val)
	{
		items.insertFirst(val);
		count++;
		return true;
	}
	bool remove(const t& val)
	{
		int n = getFrequency(val,getHead());
		if (n == 0)
			return false;
		for (int i = 0; i < n; i++)
		{
			items.del(val);
		}
		return true;

	}
	void clear()
	{
		items.clear();
	}
	int getFrequency(t val, Node<t>*hd)const
	{
		if (hd == NULL)
			return 0;
		else
		{
			if (hd->getData() == val)
				return 1 + getFrequency(val, hd->getNext());
			else
				return getFrequency(val, hd->getNext());
		}
	}
	bool contains(const t& val)const
	{
		return getFirstPointer(val,getHead()) != NULL;
	}
	vector<t>toVector()const
	{
		vector<t>tmp;
		for (Node<t>* hd=items.getHead(); hd != NULL; hd = hd->getNext())
		{
			tmp.push_back(hd->getData());
		}
		return tmp;
	}
	Node<t>*getHead()const
	{
		return items.getHead();
	}
	void display()
	{
		items.display();
	}
};

