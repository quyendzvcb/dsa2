#include<iostream>
#include<fstream>
using namespace std;
#define MAX 20
struct Node {
	int info;
	Node*next;
	Node*First[MAX];
};
void init(Node*First[]) {
	for (int i = 0; i < MAX; i++) {
		First[i] = NULL;
	}
}
void insertFirst(Node*&head, int x) {
	Node *p= new Node;
	p->info = x;
	p->next = head;
	head = p;
}
void input(Node*First[],int &n) {
	int x, k, d;
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap dinh thu " << i + 1<<": ";
		cin >> d;
		insertFirst(First[i], d);
		cout << "Nhap so canh ke cua dinh: ";
		cin >> k;
		for (int j = 0; j < k; j++) {
			cout << "Nhap canh ke thu " << j + 1 <<": ";
			cin >> x;
			insertFirst(First[i], x);
		}
	}
}
void readFile(Node*First[]) {
	ifstream myFile("doThi.txt");
	if (myFile.is_open()) {
		for (int i = 0; !myFile.eof(); i++) {
			myFile >> First[i]->info;
		}
	}

}
void output(Node*First[], int n) {
	for (int i = 0; i < n; i++) {
		Node*p = First[i];
		while (p != NULL) {
			cout << p->info << "\t";
			p = p->next;
		}
		cout << endl;
	}
}
int main() {
	Node*First[MAX];
	int n;
	init(First);
	input(First, n);
	output(First, n);
	system("pause");
	return 0;
}