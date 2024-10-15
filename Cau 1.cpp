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
int main() {
	int a[MAX], n;
	inputArr(a, n);
	outputArr(a, n);
	system("pause");
	return 0;
}