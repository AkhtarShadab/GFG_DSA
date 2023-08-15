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
	struct Node* left;
	struct Node* right;

	Node(int x) {
		data = x;
		left = right = NULL;
	}
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
	if (node == NULL) return;

	/* then print the data of node */
	printf("%d ", node->data);

	/* first recur on left child */
	preOrder(node->left);

	/* now recur on right child */
	preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int in[n], post[n];
		for (int i = 0; i < n; i++) cin >> in[i];
		for (int i = 0; i < n; i++) cin >> post[i];
		Node* root = buildTree(in, post, n);
		preOrder(root);
		cout << endl;

	}
	return 0;
}


Node *Ctree(int in[], int post[], int n, int s, int e, int &postIndex)
{
	if (s > e) return NULL;
	Node *root = new Node(post[postIndex--]);

	int index = -1;
	for (int i = s; i <= e; ++i)
	{
		if (in[i] == root->data)
		{
			index = i;
			break;
		}
	}
	root->right = Ctree(in, post, n, index + 1, e, postIndex);
	root->left = Ctree(in, post, n, s, index - 1, postIndex);

	return root;
}

Node *buildTree(int in[], int post[], int n) {
	// Your code here
	int s = 0, e = n - 1;
	int postIndex = n - 1;
	Node *root = Ctree(in, post, n, s, e, postIndex);
	return root;
}
