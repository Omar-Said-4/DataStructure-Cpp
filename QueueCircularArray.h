#pragma once
#define max 5
template<class t>
class QueueCircularArray
{
private:
	t arr[max];
	int front;
	int back;
	int count;
	int nextOf(int indx) {
		return (indx + 1) % max;
	}
public:
	QueueCircularArray()
	{
		front = 0;
		back = 0;
		count = 0;
	}
	bool isEmpty()
	{
		return count == 0;
	}
	bool isFull()
	{
		return count == max;
	}
	bool enqueue(t val)
	{
		if (isFull())
			return false;
		if (isEmpty())
		{
			arr[front] = val;
		}
		arr[back] = val;
		back = nextOf(back);
		count++;
		return true;
	}
	bool dequeue()
	{
		if (isEmpty())
			return false;
		front = nextOf(front);
		count--;
		return true;
	}
	t peekFront()
	{
		return arr[front];
	}
};

