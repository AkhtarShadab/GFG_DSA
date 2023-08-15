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
	struct Node *next;

	Node(int x) {
		data = x;
		next = NULL;
	}
};

struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

void push(struct Node **head_ref, int new_data) {

	struct Node *new_node = new Node(new_data);

	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void convert(Node *head, TreeNode *&root);

void lvl(TreeNode *r) {
	if (r == NULL) return;
	queue<TreeNode *> q;
	q.push(r);
	while (!q.empty()) {
		TreeNode *j = q.front();
		cout << j->data << " ";
		q.pop();
		if (j->left) q.push(j->left);
		if (j->right) q.push(j->right);
	}
}

void reverses(Node **head) {
	Node *prev = NULL;
	Node *cur = *head;
	Node *nxt;
	while (cur != NULL) {
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}
	*head = prev;
}
void inorder(TreeNode* root)
{
	if (root == NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void Preorder(TreeNode* root)
{
	if (root == NULL) return;
	cout << root->data << " ";
	inorder(root->left);

	inorder(root->right);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int T, i, n, l, k;

	cin >> T;

	while (T--) {
		struct Node *head = NULL;

		cin >> n;
		for (i = 1; i <= n; i++) {
			cin >> l;
			push(&head, l);
		}
		reverses(&head);
		TreeNode *root = NULL;
		convert(head, root);
		if (root == NULL) cout << "-1\n";
		lvl(root);
		cout << endl;
		inorder(root);
		cout << endl;
		Preorder(root);
		getchar();
	}
	return 0;
}


void convert(Node *head, TreeNode *&root) {
	// Your code here
	if (head == NULL) return;
	root = new TreeNode( head->data);
	head = head->next;
	queue<TreeNode*> q;
	q.push(root);
	while (head != NULL)
	{
		TreeNode *parent = q.front();
		q.pop();
		TreeNode *left = NULL , *right = NULL;
		left = new TreeNode(head->data);
		head = head->next;
		if (head != NULL) {right = new TreeNode(head->data); head = head->next;}
		q.push(left);
		q.push(right);
		parent->left = left;
		parent->right = right;
	}


}