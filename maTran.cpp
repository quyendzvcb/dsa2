#include<iostream>
#include<fstream>
using namespace std;
#define MAX 100

void readFile(int a[][MAX], int &m) {
	ifstream myFile("point.txt");
	if (myFile.is_open()) {
		int n;
		myFile >> n;
		m = (n + 2) / 2;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			int x, y;
			myFile >> x >> y;
			a[x][y] = a[y][x] = 1;
		}
		myFile.close();
	}
}
void inputFile(int a[][MAX], int m) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout<<a[i][j]<<" ";
		}
		cout << endl;
	}
}
int main() {
	int a[MAX][MAX];
	int m;
	readFile(a, m);
	inputFile(a, m);
	system("pause");
	return 0;
}