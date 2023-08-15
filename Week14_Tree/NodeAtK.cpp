#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}


int printKDistantfromLeaf(Node* node, int k);

// Function to Build Tree
Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

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
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

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
	while (t--)
	{
		string s, ks;
		getline(cin, s);
		Node* root = buildTree(s);
		getline(cin, ks);
		int k = stoi(ks);
		cout << printKDistantfromLeaf(root, k) << endl;
	}
	return 0;
}

void traverse(Node *root, int k, deque<Node*> &dq, unordered_set<Node*> &st)
{
	if (root == NULL)
	{
		Node *temp = dq.back();
		if (dq.size() > k and temp->left == NULL and temp->right == NULL)
		{
			int n = dq.size();
			st.insert(dq[n - k - 1]);
		}
		return;
	}
	dq.push_back(root);
	traverse(root->left, k, dq, st);
	traverse(root->right, k, dq, st);
	dq.pop_back();

}

int printKDistantfromLeaf(Node* root, int k)
{
	//Add your code here.
	deque<Node*> dq;
	unordered_set<Node*> st;
	traverse(root, k, dq, st);
	int ans = st.size();
	for (auto &v : st)
	{
		cout << v->data << " ";
	}
	return ans;
}