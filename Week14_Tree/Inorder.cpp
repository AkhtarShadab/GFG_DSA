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
	Node* left;
	Node* right;

	Node(int val) {
		data = val;
		left = right = NULL;
	}
};

class Solution {
public:
	// Function to return a list containing the inorder traversal of the tree.
	vector<int> inOrder(Node* root) {
		// Your code here
		vector<int> ans;
		InOrder(root, ans);
		return ans;
	}
	void InOrder(Node *root, vector<int> &ans)
	{
		if (root == NULL ) return;
		if (root->left != NULL) InOrder(root->left, ans);
		ans.push_back(root->data);
		if (root->right != NULL ) InOrder(root->right, ans);
	}
};
Node* buildTree(string str) {
	// Corner Case
	if (str.length() == 0 || str[0] == 'N') return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str;) ip.push_back(str);

	// Create the root of the tree
	Node* root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size()) break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int t;
	string tc;
	getline(cin, tc);
	t = stoi(tc);
	while (t--) {
		string s;
		getline(cin, s);
		Node* root = buildTree(s);

		Solution ob;
		vector<int> res = ob.inOrder(root);
		for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}
