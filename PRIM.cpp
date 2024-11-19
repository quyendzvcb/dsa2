#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
struct edges {
	int x, y, w;
};
#define MAX 100
void initGraph() {
	int n = -1;
}
void inputGraphFromText(int a[][MAX], int &n) {
	ifstream myFile("matrantrongso1.txt");
	if (myFile.is_open()) {
		string name;
		myFile >> n;
		for (int i = 0; i < n; i++) {
			myFile >> name;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				myFile >> a[i][j];
			}
		}
		myFile.close();
	}
}
void inputGraph(int a[][MAX], int &n) {
	cout << "Nhap so dinh cua ma tran: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap vao dong thu " << i << ": ";
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
}
void outputGraph(int a[][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void prim(int a[][MAX], int u, int n) {
	bool Tree[MAX];
	for (int i = 0; i < MAX; i++)
		Tree[i] = false;
	edges sp[MAX];
	int d = 0, size = 0;
	Tree[u] = true;
	while (size < n - 1) {
		int min_w = INT_MAX;
		int X = -1, Y = -1;
		for (int i = 0; i < n; i++) {
			if (Tree[i] == true) {
				for (int k = 0; k < n; k++) {
					if ((i == 0 && k == 1) || (k == 0 && i == 1))
						continue;
					int j = k, wei = a[i][j];
					if (wei != 0 && Tree[j] == false && wei < min_w) {
						min_w = wei;
						X = j, Y = i;
					}
				}
			}
		}
		if (X != -1 && Y != -1) {
			edges temp;
			temp.x = Y;
			temp.y = X;
			temp.w = min_w;
			sp[size++] = temp;
			Tree[X] = true;
			d += min_w;
		}
	}
	for (int i = 0; i < size; i++)
		cout << sp[i].x << " - " << sp[i].y << " : " << sp[i].w << endl;
	cout << "Weight of Tree: " << d << endl;
}
int main() {
	int a[MAX][MAX];
	int n = 0;
	int choose, x;
	system("cls");
	cout << "\n========== BAI TAP 4, CHUONG 6 , TIM KHUNG CAY TOI THIEU, PRIM ==========\n";
	cout << "1> Khoi tao MA TRAN KE rong\n";
	cout << "2> Nhap MA TRAN KE tu file text\n";
	cout << "3> Nhap MA TRAN KE\n";
	cout << "4> Xuat MA TRAN KE\n";
	cout << "5> Tim KHUNG CAY TOI THIEU bang PRIM\n";
	cout << "6> Thoat!!\n";
	cout << "=========================================================================\n";
	do {
		cout << "\nVui long chon thuc hien: ";
		cin >> choose;
		switch (choose) {
		case 1: 
			initGraph();
			cout << "Ban vua moi khoi tao MA TRAN KE thanh cong!!\n";
			break;
		case 2: 
			inputGraphFromText(a, n);
			cout << "Ban vua nhap MA TRAN KE tu file\n";
			outputGraph(a, n);
			break;
		case 3:
			inputGraph(a, n);
			break;
		case 4:
			if (n == 0) {
				cout << "Ban chua khoi tao MA TRAN KE!!";
			}
			else {
				outputGraph(a, n);
			}
			break;
		case 5: 
			cout << "Nhap dinh xuat phat: ";
			cin >> x;
			prim(a, x, n);
			break;
		case 6:
			cout << "Goodbye .....!" << endl;
			break;
		default:
			cout << "Vui long nhap lai!!";
			break;
		}
	} while (choose!=6);
	system("pause");
	return 0;
}