#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
struct Node {
	int data;
	Node *right;
	Node *left;

	Node(int x) {
		data = x;
		right = NULL;
		left = NULL;
	}
};

bool search(Node *root, int x);

Node *insert(Node *tree, int val) {
	Node *temp = NULL;
	if (tree == NULL) return new Node(val);

	if (val < tree->data) {
		tree->left = insert(tree->left, val);
	} else if (val > tree->data) {
		tree->right = insert(tree->right, val);
	}

	return tree;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	while (T--) {
		Node *root = NULL;

		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int k;
			cin >> k;
			root = insert(root, k);
		}

		int s;
		cin >> s;

		cout << search(root, s);
		cout << endl;
	}
	return 0;
}


bool search(Node* root, int x) {
	// Your code here
	if (root == NULL) return false;
	if (root->data == x)
	{
		return true;
	}
	if (root->data > x)
	{
		return  search(root->left, x);
	}
	return search(root->right, x);
}