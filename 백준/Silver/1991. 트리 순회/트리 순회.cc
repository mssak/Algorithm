#include <iostream>
using namespace std;

int n;
char lc[30];
char rc[30];

void preorder(char root) {
	if (root != '.') {
		cout << root;
		preorder(lc[root - 'A']);
		preorder(rc[root - 'A']);
	}
}

void inorder(char root) {
	if (root != '.') {
		inorder(lc[root - 'A']);
		cout << root;
		inorder(rc[root - 'A']);
	}
}

void postorder(char root) {
	if (root != '.') {
		postorder(lc[root - 'A']);
		postorder(rc[root - 'A']);
		cout << root;
	}
}

int main(void)
{
	cin >> n;
	char p, l, r;
	for (int i = 0; i < n; i++) {
		cin >> p >> l >> r;
		lc[p - 'A'] = l;
		rc[p - 'A'] = r;
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	return 0;
}