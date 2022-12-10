#include<iostream>
using namespace std;

void display(int* ,int);
void mergeSort(int*, int*, int, int);
void merge(int*, int*, int, int, int);
int main() {
	int n, * a, * aux;
	srand(0);
	n = rand() % 300;
	a = new int[n];
	aux = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = (rand() % 1000);
	}
	display(a,n);
	mergeSort(a, aux, 0, n - 1);
	display(a, n);
	return 0;
}
void display(int* a ,int n) {
	for (int i = 0; i < n-1; i++) {
		cout << a[i] << " ";
	}
	cout << a[n - 1] << ".\n";
}
void mergeSort(int* a, int* aux, int lo, int hi) {
	if (lo >= hi) {
		return;
	}
	int mid = (lo + hi) / 2;
	mergeSort(a, aux, lo, mid);
	mergeSort(a, aux, mid + 1, hi);
	merge(a, aux, lo, mid, hi);
}
void merge(int* a, int* aux, int lo, int mid, int hi) {
	for (int i = lo; i <= hi; i++) {
		aux[i] = a[i];
	}
	int i = lo;
	int j = mid+1;
	for (int k = lo; k <= hi; k++) {
		if (i > mid) {
			a[k] = aux[j++];
		}
		else if (j > hi) {
			a[k] = aux[i++];
		}
		else if (aux[i] < aux[j]) {
			a[k] = aux[i++];
		}
		else {
			a[k] = aux[j++];
		}
	}
}