/*Write a program that uses a FIFO queue to store integer number and do the following tasks:
	enqueue values:9 8 1 3 7 9 4,
	dequeue 3 numbers,
	display number of elements in queue,
	display queue,
	remove all itms from queue.
*/
#include<iostream>
#include<queue>
using namespace std;


int main() {
	queue<int> q;
	int k = 0;
	q.push(9);
	q.push(8);
	q.push(1);
	q.push(3);
	q.push(7);
	q.push(9);
	q.push(4);
	cout << "Dequeue 3 numbers..." << endl;
	q.pop();
	q.pop();
	q.pop();
	cout << "The number of elements in the Queue is: " << q.size() << ".\ndisplaying/deleting Queue :" << endl;
	k = q.size();
	for (int i = 0; i < k; i++) {
		cout << q.front() << endl;
		q.pop();
	}
	cout << "The number of elements in the Queue is: " << q.size() << endl;
	return 0;
}
