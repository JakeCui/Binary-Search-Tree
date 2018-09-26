//ZIHAO CUI EECS 2510 9/26/2018

#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_
#include <string>
using namespace std;

typedef string Key;
typedef int Value;


struct Node                //Node of the tree
{
	Key key;               //Key store the string
	Value value;           //Value store the value of the string
	Node *left;            //left child
	Node *right;           //right child

	Node(Key key, Value value)
	{
		this->key = key;
		this->value = value;
		this->left = NULL;
		this->right = NULL;

	}
	Node(Node *node)
	{
		this->key = node->key;
		this->value = node->value;
		this->left = node->left;
		this->right = node->right;
	}

};
class BST
{
private:

	Node *insert(Node *node, Key key);                     //insert the node
	Node *remove(Node *node, Key key);                     //delete the node of the key
	Node *search(Node *node, Key key);                     //search the mode of the key
	Node *minimum(Node *node);                             //find minimum node of the tree
	Node *maximum(Node *node);                             //find maximun node of the tree
	Node *Successor(Node *node, Key key);                  //find successor of the node
	Node *Predecessor(Node *node, Key key);                //find predecessor of the node
	void inOrder(Node *node);                              //list in order


	Node *removeMin(Node *node);                           //remove the min under the node (using in the delete function)
	Node *removeMax(Node *node);                           //remove the max under the node (not use, just for the symmetry of the code)


public:
	Node *root;
	int count;

	BST();
	~BST();

	void insert(Key key);
	void remove(Key key);
	Value search(Key key);
	Key minimum();
	Key maximum();
	Key Successor(Key key);
	Key Predecessor(Key key);
	void inOrder();
};

#endif
