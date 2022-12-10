/*Use a Queue to reverse an entered number, example:12345 output:54321.
*/
#include<iostream>
#include<queue>
using namespace std;

int main() {
	queue<int> q;
	int u, n, s;
	cout << "Enter a nb to reverse" << endl;
	cin >> n;
	s = n;
	while (n != 0) {
		u = n % 10;
		q.push(u);
		n /= 10;
	}
	cout << "The reverse of " << s << " is: ";
	while (q.size() > 0) {
		cout << q.front();
		q.pop();
	}
	cout << "." << endl;
	return 0;
}