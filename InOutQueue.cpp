/*write a function InOut that takes in arguments:
	1)a queue,		2)n1:the nb df element to enqueue	3)n2:the nb of element to dequeue.
	FunctioninOut enqueue n1 nodes, then dequeue n2 nodes and finally returns the number of nodes in the queue. Data in the queue is of type int. All data have the value 0.

	Write a program that creates a queue and call N times the function inOut with random values of n1 and n2 such as n1 and n2 take the values between 0 and 9. Your program should display for each call of inOut the size of the queue, then calculate the average size of the queue for the N values of n1 and n2. For each call of inOut, we don’t reinitialize the queue, i.e. between two successive call of inOut, we may have nodes in the queue.

	Execution example :
	Input N:10 
	n1=5; n2=4; Queue Size=1
	n1=7; n2=1; Queue Size=7 
	n1=4; n2=8; Queue Size=3 
	n1=3; n2=7; Queue Size=0 
	n1=7; n2=0; Queue Size=7 
	n1=6; n2=5; Queue Size=8 
	n1=1; n2=1; Queue Size=8
	n1=1; n2=7; Queue Size=2 
	n1=3; n2=0; Queue Size=5 
	n1=7; n2=9; Queue Size=3 
	Queue average size: 4.4.
*/
#include<iostream>
#include<queue>
using namespace std;

void inOut(queue<int>&, int, int);

int main() {
	int N, n1, n2, tmp;
	int avg = 0;
	queue<int> q;
	do {
		cout << "Enter N: ";
		cin >> N;
		cout << endl;
	} while (	N <= 0);
	for (int i = 0; i < N; i++) {
		n1 = rand() % 10;
		n2 = rand() % 10;
		if (n1 < n2) {
			tmp = n1;
			n1 = n2;
			n2 = tmp;
		}
		inOut(q, n1, n2);
		cout << endl << "n1=" << n1 << "; n2=" << n2 << ";  Queue size=" << q.size();
		avg += q.size();
	}
	cout << endl << "Queue average size=" << avg / N << "." << endl;
	return 0;
}

void inOut(queue<int>& q, int n1, int n2) {
	for (int i = 0; i < n1; i++) {
		q.push(0);
	}
	for (int i = 0; i < n2; i++) {
		q.pop();
	}
}