#include<iostream>
using namespace std;
#define MAX 100
void inputArr(int a[], int &n) {
	do {
		cout << "Nhap so phan tu cho mang: ";
		cin >> n;
	} while (n <= 0 || n > MAX);
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}
void outputArr(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}
void insertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
int main() {
	int a[MAX], n;
	inputArr(a, n);
	insertionSort(a, n);
	outputArr(a, n);
	system("pause");
	return 0;
}