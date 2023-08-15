#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
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


struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
}*head;

Node *findNode(Node* head, int search_for)
{
	Node* current = head;
	while (current != NULL)
	{
		if (current->data == search_for)
			break;
		current = current->next;
	}
	return current;
}


void insert()
{
	int n, i, value;
	Node *temp;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &value);
		if (i == 0)
		{
			head = new Node(value);
			temp = head;
			continue;
		}
		else
		{
			temp->next = new Node(value);
			temp = temp->next;
			temp->next = NULL;
		}
	}
}

/* Function to print linked list */
void printList(Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout << endl;
}


class Solution
{
public:
	//Function to delete a node without any reference to head pointer.
	void deleteNode(Node *del)
	{
		// Your code here

		del->data = del->next->data;
		del->next = del->next->next;
	}

};




int main(void)
{
	/* Start with the empty list */
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	int t, k, n, value;

	scanf("%d", &t);
	while (t--)
	{
		insert();
		scanf("%d", &k);
		Node *del = findNode(head, k);
		Solution ob;
		if (del != NULL && del->next != NULL)
		{
			ob.deleteNode(del);
		}
		printList(head);
	}
	return (0);
}
