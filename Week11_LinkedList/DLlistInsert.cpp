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
	struct Node *next;
	struct Node *prev;
	Node(int x)
	{
		data = x;
		next = prev = NULL;
	}
};

ll binary_exponentiation(ll a, ll b, ll m)
{
	ll ans = 1;
	while (b)
	{
		if (b % 2 == 1)
		{
			ans = (ans * a) % m;
		}
		a = (a * a) % m;
		b /= 2;
	}
	return ans;
}

void addNode(Node *head, int pos, int data)
{
	// Your code here
	Node *X = new Node(data);
	Node *ptr = head;
	for (int i = 0; i < pos; i++)
	{
		if (ptr->next == NULL) break;
		ptr = ptr->next;
	}
	if (ptr->next == NULL)
	{
		ptr->next = X;
		X->prev = ptr;
		X->next = NULL;
	}
	else
	{
		X->next = ptr->next;
		ptr->next = X;
		X->prev = ptr;

		X->next->prev = X;
	}
}

Node *insert(Node *head, int x)
{
	if (head == NULL)
	{
		return new Node(x);
	}
	Node *n = new Node(x);

	head->next = n;
	n->prev = head;
	head = n;
	return head;
}


void printList(Node *head)
{
	// The purpose of below two loops is
	// to test the created DLL
	Node *temp = head;
	if (temp != NULL) {

		while (temp->next != NULL)
			temp = temp->next;
		while (temp->prev != NULL)
			temp = temp->prev;
	}
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}

	cout << endl;
}


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
		Node *head = NULL;
		Node *root = NULL;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			head = insert(head, x);
			if (root == NULL) root = head;
		}
		head = root;
		int pos, data;
		cin >> pos >> data;
		addNode(head, pos, data);
		printList(head);
	}
	return 0;
}
