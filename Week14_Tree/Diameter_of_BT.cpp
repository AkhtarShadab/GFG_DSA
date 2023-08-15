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
};
Node* newNode(int val) {
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
Node* buildTree(string str) {
	// Corner Case
	if (str.length() == 0 || str[0] == 'N') return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str;) ip.push_back(str);

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
		if (i >= ip.size()) break;
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
class Solution {
public:
	// Function to return the diameter of a Binary Tree.

	int diameter(Node* root) {
		// Your code here
		int ans = 0;
		int check = height(root, ans);
		return ans;
	}
	int height(Node* root, int &ans)
	{

		if (root == NULL) return 0;
		int lh = height(root->left, ans) ;
		int rh = height(root->right, ans) ;

		ans = max(ans, lh + rh + 1);
		// cout << ans << " " << lh << " " << rh << endl;

		return 1 + max(lh, rh);

	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	getchar();
	while (t--)
	{
		string s;
		getline(cin, s);
		Node* root = buildTree(s);
		Solution ob;
		cout << ob.diameter(root) << endl;

	}
	return 0;
}
