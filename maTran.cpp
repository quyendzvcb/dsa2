#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define MAX 100
void xuatMaTran(int a[][MAX], int &n) {
	cout << "Nhap so phan tu cua ma tran: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}
}
int demDongFile(int a[][MAX], int &m) {
	ifstream myFile("point.txt");
	string tmp;
	if (myFile.is_open()) {
		while (!myFile.eof()) {
			getline(myFile, tmp, '\n');
			m++;
		}
		myFile.close();
	}
	return m;
}
void docFile(int a[][MAX], int &n) {
	ifstream myFile("point.txt");
	if (myFile.is_open()) {
		int x, y;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = 0;
			}
		}
		for (int i = 0; i < 12; i++) {
			myFile >> x >> y;
			a[x][y] = a[y][x] = 1;
		}
		myFile.close();
	}
}
void xuatFile(int a[][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	int a[MAX][MAX];
	int m = 0;
	int n = (demDongFile(a, m) + 2)/2;
	docFile(a, n);
	xuatFile(a, n);
	system("pause");
	return 0;
}