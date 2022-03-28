#pragma once
#define Max_Value 100
#include"Bag.h"
template<class t>
class BagArray:public Bag<t>
{
private:
	t items[Max_Value];
	int count;
	int getFirstIndex(const t &val,int ind=0)const
	{
		if (ind == count)
			return -1;
		else if (items[ind] == val)
		{
			return ind;
		}
		return getFirstIndex( val, ind + 1);
	}
	void shift(int ind)
	{
		for (int i = ind; i < count - 1; i++)
			items[i] = items[i + 1];
	}
public:
	BagArray()
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
		 if (count == Max_Value)
			 return false;
		 items[count++] = val;
		 return true;
	 }
	 bool remove(const t& val)
	 {
		 int n = getFrequency(val);
		 if (n == 0)
			 return false;
		 for (int i = 0; i < n; i++)
		 {
			 int tmp = getFirstIndex(val);
			 shift(tmp);
			 count--;
		 }
		 return true;

	 }
	 void clear()
	 {
		 count = 0;
	 }
	 int getFrequency(t val, int ind = 0)const
	 {
		 if (ind == count)
			 return 0;
		 else
		 {
			 if (items[ind] == val)
				 return 1 + getFrequency(val, ind + 1);
			 else
				 return getFrequency(val, ind + 1);
		 }
	 }
	 bool contains(const t& val)const
	 {
		 return getFirstIndex(val)!=-1;
	 }
	 vector<t>toVector()const
	 {
		 vector<t>tmp;
		 for (int i = 0; i < count; i++)
		 {
			 tmp.push_back(items[i]);
		 }
		 return tmp;
	 }
	 void display()
	 {
		 for (int i = 0; i < count; i++)
			 cout << items[i] << " ";
	 }
};

