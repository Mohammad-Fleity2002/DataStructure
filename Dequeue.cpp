/*
We aim to implement a new data structure called Deque.The main operations to do in Deque are called : 
push_front, push_back,		pop_front and pop_back.		Each with complexity O(1).
Other operations are :
frontand		end.		Each with complexity O(1).
Implement Deque and its operations using linked list or array implementation.
Data in Deque are integers.Example : consider many random numbers in sequence : 2, 4, 6, 8, 10, 12, 14.
We need to put them in Deque by using the following operations : 
if we use push_front for the first four numbers, Deque becomes : 8, 6, 4, 2, 
then if we use push_back for the next three numbers, Deque becomes : 8, 6, 4, 2, 10, 12, 14. 
The front function returns 8, and the end function returns 14. 
If we do pop_front, the front number 8 is removed.If we do pop_back, the end number 14 is removed.
*/
#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prv;
};
struct Deque {
	Node* head;
	Node* tail;
};
void push_front(Deque&, int);
void push_back(Deque&, int);
bool pop_front(Deque&);
bool pop_back(Deque&);
bool isEmpty(Deque);
void initialize(Deque&);
void display(Deque);
int front(Deque);
int back(Deque);
int main() {
	int n, m;
	Deque d;
	srand(0);
	initialize(d);
	//n = 10;
	n = (rand() % 20) + 1;
	cout << "n: " << n << endl;
	for (int i = 0; i < n/2; i++) {
		m = rand() % 100;
		cout << m << " ";
		push_front(d, m);
	}
	cout << endl;// << "Done push_Front.\n";
	for (int i = 0; i < (n - n / 2); i++) {
		m = rand() % 100;
		cout << m << " ";
		push_back(d, m);
	}
	cout << endl;
	//cout << endl << "Done push_back.\ndisplaying....\n";
	display(d);
	//display(d);
	return 0;
}
void push_back(Deque& d, int m) {
	Node* tmp = new Node;
	tmp->data = m;
	tmp->next = tmp->prv = NULL;
	if (isEmpty(d)) {
		d.head = d.tail = tmp;
		return;
	}
	tmp->prv = d.tail;
	d.tail->next = tmp;
	d.tail = tmp;
}
void push_front(Deque& d, int m) {
	Node* tmp = new Node;
	tmp->data = m;
	tmp->next = tmp->prv = NULL;
	if (isEmpty(d)) {
		d.head = d.tail = tmp;
		return;
	}
	d.head->prv = tmp;
	tmp->next = d.head;
	d.head = tmp;
}
bool isEmpty(Deque d) {
	return d.tail == NULL;
}
void initialize(Deque& d) {
	d.head = d.tail = NULL;
}
bool pop_back(Deque& d) {
	if (isEmpty(d)) {
		return false;
	}
	d.tail = d.tail->prv;
	return true;
}
bool pop_front(Deque& d) {
	if (isEmpty(d)) {
		return false;
	}
	d.head = d.head->next;
	return true;
}
int front(Deque d) {
	if (isEmpty(d)) {
		return 0;
	}
	return d.head->data;
}
int back(Deque d) {
	if (isEmpty(d)) {
		return 0;
	}
	return d.tail->data;
}
void display(Deque d) {
	if (isEmpty(d)) {
		cout << "Empty deque!!!!!!!!!!!" << endl;
		return;
	}
	Node* cur = d.head;
	while (cur->next) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << cur->data << "." << endl;
}