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


struct Node* pairwise_swap(struct Node* head)
{
	// your code here
	if (head->next == NULL) return head;
	Node *start = head->next->next;
	Node *prev = head;
	head = head->next;
	head->next = prev;
	while (start != NULL and start->next != NULL)
	{
		prev->next = start->next;
		prev = start;
		Node *nxt = start->next->next;
		start->next->next = start;
		start = nxt;
	}
	prev->next = start;
	return head;

}


void printList(struct Node* node)
{
	while (node != NULL)
	{
		printf("%d ", (node)->data);
		node = (node)->next;
	}
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

		int n, l, firstdata;
		cin >> n;
		// taking first node of linked list
		cin >> firstdata;
		struct Node* head = new Node(firstdata);
		struct Node* tail = head;
		// taking remaining nodes of linked list
		for (int i = 1; i < n; i++)
		{
			cin >> l;
			tail->next = new Node(l);
			tail = tail->next;
		}
		head = pairwise_swap(head);
		printList(head);
		cout << endl;

	}
	return 0;
}
