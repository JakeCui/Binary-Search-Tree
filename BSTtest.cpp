//ZIHAO CUI EECS 2510 9/26/2018

#include <iostream>
#include "BST.h"
#include "BSTtest.h"
using namespace std;


int main()
{
	BST *bst = new BST();
	BSTtest *bstT = new BSTtest();

	string command;
	Key key;

	cout << "--------" << "Binary Search Tree(BST)" << " " << "EECS 2510" << " " << "ZIHAO CUI" << "--------" << endl;
	cout << endl;

	bstT->help();

	// command loop

	do 
	{
		cin >> command;
		if (command.compare("max") == 0 || command.compare("min") == 0 || command.compare("list") == 0 || command.compare("help") == 0 || command.compare("exit") == 0)
		{
			if (command.compare("min") == 0)
			{

				cout << bst->minimum() << endl;

			}
			if (command.compare("max") == 0)
			{
				cout << bst->maximum() << endl;

			}
			if (command.compare("list") == 0)
			{
				bst->inOrder();

			}
			if (command.compare("help") == 0)
			{
				bstT->help();

			}

		}
		else
		{
			cin >> key;

			if (command.compare("insert") == 0)
			{
				bst->insert(key);
			}
			if (command.compare("delete") == 0)
			{
				bst->remove(key);
			}
			if (command.compare("search") == 0)
			{
				cout << key << " " << bst->search(key) << endl;


			}
			if (command.compare("next") == 0)
			{
				cout << bst->Successor(key) << endl;


			}
			if (command.compare("prev") == 0)
			{
				cout << bst->Predecessor(key) << endl;


			}
		}

	} while (command != "exit");

	return 0;
}


//show the help list
void BSTtest::help()
{
	cout << "-----------------  Command list  -----------------" << endl;
	cout << "insert string" << "       " << "insert string to the tree" << endl;
	cout << "delete string" << "       " << "delete the string" << endl;
	cout << "search string" << "       " << "search a string" << endl;
	cout << "min" << "                 " << "find the minimum value" << endl;
	cout << "max" << "                 " << "find the maximum value" << endl;
	cout << "next string" << "         " << "show the successor" << endl;
	cout << "prev string" << "         " << "show the predecessor" << endl;
	cout << "list string" << "         " << "list the tree in order" << endl;
	cout << "help string" << "         " << "command help" << endl;
	cout << "exit string" << "         " << "end the program" << endl;
	cout << "--------------------------------------------------" << endl;

}