#include "BST.h"

int main() {
	TreeNode* h = initialize();
	int n, d, nn = 0;
	n = (rand() % 20)+10;
	cout << "n=" << n << endl;
	for (int i = 0; i < n; i++) {
		d = rand() % 1000;
		cout << d << " ";
		h = insert(h, d);
	}
	cout << endl;
	infixITER(h);
	infixREC(h);
	cout << endl;
	//postfixITER(h);
	postfixREC(h);
	cout << endl;
	prefixITER(h);
	prefixREC(h);
	cout << endl;
	nbOfNode2(h, nn);
	cout << "Number of Nodes: " << nbOfNode1(h) << "." << endl;
	cout << "Number of Nodes: " << nn << "." << endl;
	cout << "Number of Leaves: " << nbOfLeaves(h) << "." << endl;
	displayByLevel1(h);
	displayByLevel2(h);
	TreeNode* min, * max;
	min = findMin(h);
	max = findMax(h);
	cout << "The minimum is: " <<min->data<< "." << endl;
	cout << "The maximum is: " << max->data << "." << endl;
	cout << "\nEnter a number to insert itterative way: ";
	cin >> d;
	insert_Iterative(h, d);
	infixREC(h);
	cout << "\nEnter a nb to delete: ";
	cin >> d;
	h = deleteNode(h, d);
	infixREC(h);
	cout << "\nH\t a\t k\t o\t u\t n\t a\t\t M\t a\t t\t a\t t\t a\n";
	return 0;
}
