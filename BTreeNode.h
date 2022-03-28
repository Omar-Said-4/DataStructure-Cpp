#pragma once
template<class t>
class BTreeNode
{
private:
	t data;
	BTreeNode<t>* left;
	BTreeNode<t>* right;
public:
	BTreeNode()
	{
		left = nullptr;
		right = nullptr;
	}
	BTreeNode(t val)
	{
		left = nullptr;
		right = nullptr;
		data = val;
	}
	void setData(t val) { data = val; }
	t getData() { return data; }
	void setLeft(BTreeNode<t>* val) { left = val; }
	void setRight(BTreeNode<t>* val) { right = val; }
	BTreeNode<t>* getLeft() { return left; }
	BTreeNode<t>* getRight() { return right; }
};

