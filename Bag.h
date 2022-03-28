#pragma once
#include<iostream>
#include <vector>
using namespace std;
template<class t>
class Bag
{
public:
	virtual int getCurrentSize() const = 0;
	virtual bool isEmpty()const = 0;
	virtual bool add(const t& val) = 0;
	virtual bool remove(const t& val) = 0;
	virtual void clear() = 0;
	//virtual int getFrequency(t val, int ind = 0)const = 0;
	virtual bool contains(const t& val)const = 0;
	virtual vector<t>toVector()const = 0;
	virtual~Bag() {}
};

