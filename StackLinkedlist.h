#pragma once
#include"LinkedList.h"
#include"Stack.h"
template<class t>
class StackLinkedlist:public Stack<t>
{
private:
	LinkedList<t>stack;
public:
	bool isEmpty()const
	{
		return (stack.count() == 0);
	 }
	bool push(const t& val)
	{
		stack.insertFirst(val);
		return true;
	 }
	bool pop()
	{
		return stack.deleteFirst();
	}
	t peek()
	{
		if (!isEmpty())
			return stack.getHead()->getData();
		else
			cout << "UNDERFLOW!" << endl;
	 }
	int count() 
	{ return stack.count(); }
	 ~StackLinkedlist() {}
};

