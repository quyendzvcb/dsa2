#include<iostream>
#include<stack>
#include<fstream>
using namespace std;
#define MAX 100
//struct Stack {
//	int b[MAX];
//	int top;
//};
//void init(Stack&s) {
//	s.top = -1;
//}
//void push(Stack& s, int x) {
//	s.b[++s.top] = x;
//}
//int pop(Stack &s) {
//	return s.b[s.top--];
//}
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
void DFS(int a[][MAX], int u, int n) {
	bool visisted[MAX];
	for (int i = 0; i < MAX; i++) {
		visisted[i] = false;
	}
	stack<int>s;
	s.push(u);
	while (!s.empty()) {
		int vertise = s.top();
		s.pop();
		if (visisted[vertise] == false) {
			cout << vertise << " ";
			visisted[vertise] = true;
			for (int i = n-1; i >=0; i--) {
			if (a[vertise][i] == 1 && visisted[i] == false) {
				s.push(i);
			}
		}
		}
	}
}
bool search(int a[][MAX], int n, int u, int x) {
	bool visisted[MAX];
	for (int i = 0; i < MAX; i++) {
		visisted[i] = false;
	}
	stack<int>s;
	s.push(u);
	while (!s.empty()) {
		int vertise = s.top();
		s.pop();
		if (visisted[vertise] == false) {
			if (vertise == x) {
				return true;
			}
			visisted[vertise] = true;
			for (int i = n - 1; i >= 0; i--) {
				if (a[vertise][i] == 1 && visisted[i] == false) {
					s.push(i);
				}
			}
		}
	}
	return false;
}
int main() {
	int a[MAX][MAX];
	int n = 0;
	/*inputMatrix(a, n);
	DFS(a,0, n);*/
	docFile(a, n);
	//outputMatrix(a, n);
	DFS(a, 0, n);
	cout << endl;
	if (search(a, n, 0, 7)) {
		cout << "Ton tai!!!";
	}
	else
		cout << "Khong ton tai!!";
	system("pause");
	return 0;
}