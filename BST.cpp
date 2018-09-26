//ZIHAO CUI EECS 2510 9/26/2018

#include <iostream>
#include "BST.h"
#include <string>
#include <assert.h>
using namespace std;


BST::BST()
{
	root = NULL;

	count = 0;
}

BST::~BST()
{

}

//insert function
void BST::insert(Key key)
{

	root = insert(root, key);


}

//insert the key, compare with the key in the tree,if<, will go to left,if >,go to right, if don't find the node have same key, will add a new node, if find the same key, the value of the node will +1
Node*  BST::insert(Node * node, Key key)
{
	if (node == NULL) {
		count++;
		cout << key << " " << "1" << endl;
		return new Node(key, 1);


	}
	if (key == node->key)
	{
		node->value++;
		cout << key << " " << node->value << endl;

	}
	else if (key < node->key)
	{
		node->left = insert(node->left, key);

	}
	else {
		node->right = insert(node->right, key);

	}
	return node;
}




//delete function,(Hubbard Deletion) if the node has left and right child, will delete the node, and put the min of the right subtree to the node
void BST::remove(Key key)
{
	root = remove(root, key);
}


Node*BST::remove(Node * node, Key key)
{
	if (node == NULL) {
		cout << key << " " << "-1" << endl;
		return NULL;
	}
	if (key == node->key)
	{
		node->value--;
		cout << key << " " << node->value << endl;

		if (node->value != 0)
		{
			return node;
		}
		if (node->left == NULL)
		{
			Node *rightNode = node->right;
			delete node;
			count--;
			return rightNode;
		}
		if (node->right == NULL)
		{
			Node *leftNode = node->left;
			delete node;
			count--;
			return leftNode;
		}
		Node *successor = new Node(Successor(root, key));
		successor->right = removeMin(node->right);
		successor->left = node->left;
		delete node;
		count--;
		return successor;
	}
	else
		if (key < node->key)
		{
			node->left = remove(node->left, key);
			return node;
		}
		else
		{
			node->right = remove(node->right, key);
			return node;
		}
}



//search function
Value BST::search(Key key)
{
	if (search(root, key) == NULL)
	{
		return 0;
	}
	else
	{
		return search(root, key)->value;
	}
}

//compare the key input with the key in the tree
Node *BST::search(Node* node, Key key)
{

	if (node == NULL)
	{
		return NULL;
	}


	if (key == node->key)
	{
		return (node);
	}
	else
		if (key < node->key)
		{
			return search(node->left, key);
		}
		else
		{
			return search(node->right, key);
		}
}


//minimum function
Key BST::minimum()
{
	if (BST::count == 0)
	{
		return "--------";
	}
	Node* minNode = minimum(root);
	return minNode->key;
}

// find the most left node
Node* BST::minimum(Node* node)
{
	if (node->left == NULL)
	{
		return node;
	}
	else {
		return minimum(node->left);
	}
}



//maximum function
Key BST::maximum()
{
	if (BST::count == 0)
	{
		return "--------";
	}
	Node* maxNode = maximum(BST::root);
	return maxNode->key;
}

//find the most right node
Node* BST::maximum(Node* node)
{
	if (node->right == NULL)
	{
		return node;
	}
	else
	{
		return maximum(node->right);
	}
}



//successor
Key BST::Successor(Key key)
{
	if (Successor(root, key) == NULL)
	{
		return "--------";
	}
	else
	{
		return Successor(root, key)->key;
	}
}

//find the min of the right subtree
Node *BST::Successor(Node *node, Key key) {
	if (search(node, key) == NULL)
	{
		return NULL;
	}
	else {
		if (search(node, key)->right == NULL)
		{
			return NULL;
		}
		else
		{
			return minimum(search(node, key)->right);
		}
	}
}


//predecessor
Key BST::Predecessor(Key key)
{
	if (Predecessor(root, key) == NULL)
	{
		return "--------";
	}
	else
	{
		return Predecessor(root, key)->key;
	}
}

//fine the max of left subtree
Node *BST::Predecessor(Node *node, Key key)
{
	if (search(node, key) == NULL)
	{
		return NULL;
	}
	else {
		if (search(node, key)->left == NULL)
		{
			return NULL;
		}
		else
		{
			return maximum(search(node, key)->left);
		}
	}
}



//list in order
void BST::inOrder()
{

	inOrder(root);

}
//list left subtree, then right subtree
void BST::inOrder(Node *node)
{
	if (node != NULL)
	{
		inOrder(node->left);
		cout << node->key << " " << node->value << endl;
		inOrder(node->right);
	}

}

//remove the min 
Node* BST::removeMin(Node* node) {
	if (node->left == NULL) {
		Node* rightNode = node->right;
		delete node;
		count--;
		return rightNode;
	}
	node->left = removeMin(node->left);
	return node;
}


//remove the max
Node*BST::removeMax(Node* node) {
	if (node->right == NULL) {
		Node* leftNode = node->left;
		delete node;
		count--;
		return leftNode;
	}
	node->right = removeMax(node->right);
	return node;
}
