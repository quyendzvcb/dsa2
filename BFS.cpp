#include<iostream>
#include<queue>
#include<fstream>
using namespace std;
#define MAX 100
void inputMatrix(int a[][MAX], int &n) {
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap vao dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
}
void outputMatrix(int a[][MAX], int &n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void chuaXet(int C[MAX], int n) {
	for (int i = 0; i < n; i++) {
		C[i] = 1;
	}
}
void docFile(int a[][MAX], int &n) {
	ifstream myFile("matrix.txt");
	if (myFile.is_open()) {
		myFile >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				myFile >> a[i][j];
			}
		}
		myFile.close();
	}
}
void BFS(int a[][MAX], int u, int n) {
	bool visited[MAX];
	for (int i = 0; i < MAX; i++) {
		visited[i] = false;
	}
	queue<int> q;
	q.push(u);
	while (!q.empty()) {
		int vertise = q.front();
		q.pop();
		if (visited[vertise] == false) {
			cout << vertise << " ";
			visited[vertise] = true;
			for (int i = 0; i < n; i++) {
				if (a[vertise][i] == 1 && visited[i] == false) {
					q.push(i);
				}
			}
		}

	}
}
int main(){
	int a[MAX][MAX];
	int n = 0;
	/*inputMatrix(a, n);*/
	docFile(a, n);
	BFS(a, 0, n);
	system("pause");
	return 0;
}