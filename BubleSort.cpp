/*                                                            ---------     buble sort    ---------                                                                         */
#include<iostream>
using namespace std;

void bubleSort(int* , int );
void display(int*, int);
void swapp(int&, int&);


int main() {
	srand(0);
	int n, v;
	int* a;
	n = rand() % 30;
	a = new int[n];
	cout << "n: " << n << endl;
	for (int i = 0; i < n; i++) {
		v = rand() % 100;
		a[i] = v;
	}
	display(a,n);
	bubleSort(a, n);
	display(a,n);
	return 0;
}

void display(int* a, int n) {
	if (n == 0) {
		cout << "Empty array" << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "." << endl;
}

void bubleSort(int* a, int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1 ; j++) {
			if (a[j] > a[j + 1]) {
				swapp(a[j], a[j + 1]);
			}
			//display(a, n);
		}
	}
}
/*
void swap(int*x,int*y){
	int tmp;
	tmp=*x;
	*x=*y;
	*y=tmp;
}
void bubbleSort(int* a, int n) {
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < n - i ; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}*/
void swapp(int& a, int& b) {
	int temp;
	temp = a; 
	a = b; 
	b = temp;
}