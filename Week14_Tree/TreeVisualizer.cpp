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
	Node *left;
	Node *right;

	Node(int val) {
		data = val;
		left = right = NULL;
	}
};

// Function to Build Tree
Node *buildTree(string str) {
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str;)
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node *> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node *currNode = queue.front();
		queue.pop();

		// Get the current Node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current Node
			currNode->left = new Node(stoi(currVal));

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

			// Create the right child for the current Node
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
and a pointer to right child */
/*struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

//Function to check whether a binary tree is foldable or not.
int height(struct Node* node) {
	// code here
	if (node == NULL) return 0;
	if (node->left == NULL and node->right == NULL ) return 1;
	return max(height(node->left), height(node->right)) + 1;
}
vector<vector<int>> levelOrder(Node* node)
{
	//Your code here
	Node *temp = new Node(-1);
	queue<Node*> q;
	q.push(node);
	q.push(temp);
	int h = height(node);
	int count = 0;
	vector<string> check;
	while (q.empty() == 0)
	{
		Node *curr = q.front();
		q.pop();
		if (curr == NULL)
		{
			q.push(NULL);
			q.push(NULL);
			check.push_back(to_string(-1));
		}
		else if (curr != temp) {
			q.push(curr->left);
			q.push(curr->right);
			check.push_back(to_string(curr->data));
		}
		else if (q.empty() == 0)
		{
			q.push(temp);
			check.push_back("N");
			count++;
		}
		if (count == h) break;

	}
	vector<vector<int>> ans;
	int n = check.size();
	int i = 0;
	while (i < n)
	{
		vector<int> level;
		while (i < n)
		{
			if (check[i] == "N") break;
			level.push_back(stoi(check[i]));
			i++;
		}
		ans.push_back(level);
		i++;
	}
	return ans;
}
void TreeVisualizer(Node *root)
{
	vector<vector<int>> ans = levelOrder(root);
	for (auto &x : ans)
	{
		for (auto &y : x)
		{
			cout << y << " ";
		}
		cout << endl;
	}

}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int tc;
	scanf("%d ", &tc);
	while (tc--) {
		string treeString;
		getline(cin, treeString);
		Node *root = buildTree(treeString);
		TreeVisualizer(root);

	}
	return 0;
}