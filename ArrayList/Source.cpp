#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
struct Student {
	char name[30];
	int id;
};
struct List {
	Student* c;
	int n;
	int max;
};
int nbOfStudent(List);
int search(List, int);
void initialize(List&, int);
void display(List);
bool isFull(List);
bool isEmpty(List);
bool insert(List&, Student);
bool modify(List&, Student);
bool remove(List&, int);


int main() {
	int n, max, id, k;
	Student x;
	List l;
	
	ifstream fin;
	fin.open("student.txt", ios::in);
	if (!fin) {
		cerr << "error 1";
	}
	fin >> n >> max;
	initialize(l,max);
	for (int i = 0; i < max; i++) {
		fin >> x.id >> x.name;
		if (!insert(l,x)) {
			cout << "List is full!!" << endl;
			break;
		}
	}
	display(l);
	cout << "Enter an id to search" << endl;
	cin >> id;
	k = search(l, id);
	if (k == -1) {
		cout << "Student not found" << endl;
	}
	else {
		cout << "Student found at position: " << k << " ." << endl;
	}
	cout << "Enter the id of Student to modify:  ";
	cin >> x.id;
	cout << "Enter his new name:  ";
	cin >> x.name;
	cout << endl;
	if (!modify(l, x))
	{
		cout << "element not found!!" << endl;
	}
	else {
		cout << "Modified successfully" << endl;

	}
	cout << "Enter the id of the Student to remove " << endl;
	cin >> id;
	if (!remove(l, id)) {
		cout << "element not found!!" << endl;
	}
	else {
		cout << "Removed successfully" << endl;
	}
}

void initialize(List& l, int max) {
	l.c = new Student[max];
	l.n = 0;
	l.max = max;
}
bool isFull(List l) {
	return l.n == l.max;
}
bool isEmpty(List l) {
	return l.n == 0;
}

bool insert(List& l, Student s) {
	int k;
	if (isFull(l)) {
		return false;
	}
	for (k = 0; k < l.n; k++) {
		if (l.c[k].id >= s.id) {
			break;
		}
	}
	for (int i = l.n-1; i >= k; i--) {
		l.c[i + 1].id = l.c[i].id;
		strcpy_s(l.c[i + 1].name, l.c[i].name);
	}
	l.c[k].id = s.id;
	strcpy_s(l.c[k].name, s.name);
	l.n++;
	return true;
}

void display(List l) {
	if (isEmpty(l)) {
		cout << "Empty List!!" << endl;
		return;
	}
	for (int i = 0; i < l.n; i++) {
		cout << l.c[i].id << "  " << l.c[i].name << "." << endl;
	}
}
int search(List l, int id) {
	if (isEmpty(l)) {
		return -1;
	}
	for (int i = 0; i < l.n; i++) {
		if (l.c[i].id == id) {
			return i;
		}
	}
	return -1;
}
bool modify(List& l, Student s) {
	int k;
	k = search(l, s.id);
	if (k == -1) {
		return false;
	}
	strcpy_s(l.c[k].name, s.name);
	return true;
}

bool remove(List& l, int id) {
	int k;
	k = search(l, id);
	if (k == -1) {
		return false;
	}
	for (int i = k; i < l.n; i++) {
		l.c[i] = l.c[i + 1];
	}
	return true;
}
int nbOfStudent(List l) {
	return l.n;
}