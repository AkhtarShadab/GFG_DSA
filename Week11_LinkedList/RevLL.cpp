#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;

typedef struct Node {
	int data;
	struct Node *next;
	Node(int x)
	{
		data = x;
		next = NULL;
	}
} Node;

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

class Solution
{
public:
	//Function to reverse a linked list.
	struct Node* reverseList(struct Node *head)
	{
		// code here
		// return head of reversed list
		if (head->next == NULL) return head;
		Node *curr = head->next, *prev = head;
		head->next = NULL;
		while (curr != NULL)
		{
			Node *temp  = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		return prev;

	}

};
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp  = temp->next;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int T, n, l, firstdata;
	cin >> T;

	while (T--)
	{
		struct Node *head = NULL,  *tail = NULL;

		cin >> n;

		cin >> firstdata;
		head = new Node(firstdata);
		tail = head;

		for (int i = 1; i < n; i++)
		{
			cin >> l;
			tail->next = new Node(l);
			tail = tail->next;
		}

		Solution ob;
		head = ob. reverseList(head);

		printList(head);
		cout << endl;
	}
	return 0;
}
