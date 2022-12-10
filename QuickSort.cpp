#include<iostream>
#include<ctime>
using namespace std;

void display(int*, int);
void quickSort(int*, int, int);
void insertionSort(int*, int);
void swap(int*, int, int);
void swap(int*, int*);
int median3(int*, int, int);
int partiton(int*, int, int);



int main() {
	int n, * a;
	srand(time(0));
	n = rand() % 100;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = (rand() % 1000);
	}
	display(a, n);
	quickSort(a, 0, n - 1);
	display(a, n);
	return 0;
}
void display(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		cout << a[i] << " ";
	}
	cout << a[n - 1] << ".\n";
}
void swap(int* a, int n, int b) {
	int tmp = a[n];
	a[n] = a[b];
	a[b] = tmp;
}
int median3(int* a, int lo, int hi) {
	int mid = (lo + hi) / 2;
	if (a[lo] > a[hi]) {
		swap(a, lo, hi);
	}
	if (a[mid] < a[lo]) {
		swap(a, lo, mid);
	}
	if (a[mid] > a[hi]) {
		swap(a, mid, hi);
	}
	return mid;
}
/*int median3(int* a, int lo, int hi) { int center = (lo + hi) / 2; if (a[lo] > a[center]) { swap(a, center, lo); } if (a[lo] > a[hi])swap(a, hi, lo);
if (a[center] > a[hi])swap(a, hi,center); return center; }*/
void insertionSort(int *a, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (a[j] < a[j - 1]) {
				swap(a, j, j - 1);
			}
			else
			{
				break;
			}
		}
	}
}
void swap(int* x, int* y) {
	int tmp;
	tmp = *x; *x = *y; *y = tmp;
}
int partiton(int* a, int lo , int hi) {
	int j = hi + 1, i = lo, pivot = a[lo];
	while (true) {
		while (a[++i] < pivot) {
			if (i == hi) {
				break;
			}
		}
		while (pivot< a[--j]) {
			if (j == lo) { 
				break;
			}
		}
		if (i < j) {
			swap(&a[i], &a[j]);
		}
		else {
			break;
		}
	}
	swap(&a[lo], &a[j]);
	return j;
}
void quickSort(int* a, int lo, int hi) {
	int mid = median3(a, lo, hi);
	swap(a, lo, mid);

	if (hi <= lo + 10 - 1) {//cutoff=10
		insertionSort(a, hi + 1);//cout<<"Use INSERTION sort"<<endl;
		return;
	}
	int k= partiton(a, lo, hi);
	quickSort(a, lo, k - 1);
	quickSort(a, k + 1, hi);
}
