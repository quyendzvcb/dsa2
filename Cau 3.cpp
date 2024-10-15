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
void interchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}
int main() {
	int a[MAX], n;
	inputArr(a, n);
	interchangeSort(a, n);
	outputArr(a, n);
	system("pause");
	return 0;
}