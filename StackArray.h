#pragma once
#include"Stack.h"
#define Max_Size 1000  //Max stack size;
template<class t>
class StackArray:public Stack<t>
{
private:
	int top;
	t stack[Max_Size];
public:
	StackArray()
	{
		top = -1;
	}
	 bool isEmpty()const
	 {
		 return top == -1;
	 }
	 bool push(const t& val)
	 {
		 if (top < Max_Size - 1) {
			 stack[++top] = val;
			 return true;
		 }
		 return false;
	 }
	 int count()
	 {
		 return top + 1;
	 }
	 bool pop()
	 {
		 if (isEmpty())
			 return false;
		 top--;
		 return true;
	 }
	 t peek()
	 {
		 if (!isEmpty())
			 return stack[top];
		 else
			 cout << "UNDERFLOW!";
	 }
	 ~StackArray() {}
};

