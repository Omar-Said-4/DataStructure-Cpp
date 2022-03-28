#pragma once
#include"BTreeNode.h"
#include<iostream>
using namespace std;
template<class t>
class BinaryTree
{
private:
	BTreeNode<t>* root;
	BTreeNode<t>* Findmin(BTreeNode<t>* root)
	{
		BTreeNode<t>* curr = root;
		while (curr->getLeft())
		{
			curr = curr->getLeft();
		}
		return curr;
	}
	BTreeNode<t>* delete_Node(BTreeNode<t>* leaf, int key)
	{
		
		if (leaf == nullptr) {
			return leaf;
		}
		if (key< leaf->getData())
		{
			leaf->setLeft(delete_Node(leaf->getLeft(), key));
		}
		else if (key > leaf->getData())
		{
			leaf->setRight(delete_Node(leaf->getRight(), key));
		}
		else
		{
			if (leaf->getLeft() == nullptr && leaf->getRight() == nullptr) {
				//No child
				delete leaf;
				leaf = nullptr;
			}
			else if (leaf->getLeft() == nullptr)
			{
				//One child only
				BTreeNode<t>* tmp = leaf;
				leaf = leaf->getRight();
				delete tmp;
			}
			else if (leaf->getRight() == nullptr)
			{
				//One child only
				BTreeNode<t>* tmp = leaf;
				leaf = leaf->getLeft();
				delete tmp;
			}
			else
			{
				//two children
				BTreeNode<t>* tmp = Findmin(leaf->getRight());
				leaf->setData(tmp->getData());
				leaf->setRight(delete_Node(leaf->getRight(), tmp->getData()));

			}

		}
		return leaf;
	}
	void destroy_tree(BTreeNode<t>*leaf)
	{
		if (leaf != NULL)
		{
			destroy_tree(leaf->getLeft());
			destroy_tree(leaf->getRight());
			delete leaf;
		}
	}
	void insert_to_tree(t key, BTreeNode<t>* leaf)
	{
		if (key < leaf->getData())
		{
			if (leaf->getLeft() != nullptr)
				insert_to_tree(key, leaf->getLeft());
			else
			{
				leaf->setLeft(new BTreeNode<t>(key));
				leaf->getLeft()->setLeft(nullptr);
				leaf->getLeft()->setRight(nullptr);
			}
		}
		else
		{
			if (leaf->getRight() != nullptr)
				insert_to_tree(key, leaf->getRight());
			else
			{
				leaf->setRight(new BTreeNode<t>(key));
				leaf->getRight()->setLeft(nullptr);
				leaf->getRight()->setRight(nullptr);
			}
		}
	}
	BTreeNode<t>* search_tree(int key, BTreeNode<t>* leaf)
	{
		if (leaf != NULL)
		{
			if (key == leaf->getData())
				return leaf;
			if (key < leaf->getData())
				return search_tree(key, leaf->getLeft());
			return search_tree(key, leaf->getRight());
		}
		return nullptr;
	}
	void Preorder_print(BTreeNode<t>*leaf)
	{
		if (leaf != nullptr)
		{
			cout << leaf->getData();
			Preorder_print(leaf->getLeft());
			Preorder_print(leaf->getRight());
		}
	}
	void inorder_print(BTreeNode<t>* leaf)
	{
		if (leaf != nullptr)
		{
			inorder_print(leaf->getLeft());
			cout << leaf->getData();
			inorder_print(leaf->getRight());
		}
	}
	void postorder_print(BTreeNode<t>* leaf)
	{
		if (leaf != nullptr)
		{
			postorder_print(leaf->getLeft());
			postorder_print(leaf->getRight());
			cout << leaf->getData();
		}
	}
public:
	BinaryTree() { root = nullptr; }
	void insert(int key)
	{
		if(root!=nullptr)
		insert_to_tree(key, root);
		else
		{
			root = new BTreeNode<t>(key);
			root->setLeft(nullptr);
			root->setRight(nullptr);
		}
	}
	BTreeNode<t>* search(int key)
	{
		return search_tree(key, root);
	}
	void destroy()
	{
		destroy_tree(root);
	}
	void Preorder() { Preorder_print(root); cout << endl; }
	void inorder() { inorder_print(root); cout << endl;
	}
	void postorder() { postorder_print(root); cout << endl;
	}
	~BinaryTree()
	{
		destroy();
	}
	void deleteNode(t key)
	{
		if (search(key))
		{
			delete_Node(root, key);
		}
	}
};

