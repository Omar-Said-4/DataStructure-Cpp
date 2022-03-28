#pragma once
template<class t>
class Stack
{
public:
	virtual bool isEmpty()const = 0;
	virtual bool push(const t& val)=0;
	virtual bool pop() = 0;
	virtual t peek() = 0;
	virtual int count() = 0;
	virtual ~Stack() {}
};

