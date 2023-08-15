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
	struct Node* next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

struct Node* buildList(int size)
{
	int val;
	cin >> val;

	Node* head = new Node(val);
	Node* tail = head;

	for (int i = 0; i < size - 1; i++)
	{
		cin >> val;
		tail->next = new Node(val);
		tail = tail->next;
	}

	return head;
}

void printList(Node* n)
{
	while (n)
	{
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}


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
class Solution
{
public:
	//Function to add two numbers represented by linked list.
	struct Node* addTwoLists(struct Node* first, struct Node* second)
	{
		// code here
		first = reverseList(first);
		second = reverseList(second);
		Node *ans = NULL, *anstail = NULL;
		int carry = 0;
		while (first != NULL && second != NULL)
		{
			int val = first->data + second->data;
			bool check = 0;
			if (val > 9)
			{
				val -= 10;
				check = 1;
			}
			if (ans == NULL)
			{
				ans = new Node(val);
				anstail = ans;

			}
			else {

				anstail->next = new Node(val + carry);
				anstail = anstail->next
			}
			if (check == 1)
			{
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			first = first->next;
			second = second->next;

		}
		if (first == NULL)
		{
			while (second != NULL) {
				int val =  second->data;
				bool check = 0;
				if (val > 9)
				{
					val -= 10;
					check = 1;
				}
				if (ans == NULL)
				{
					ans = new Node(val);
					anstail = ans;

				}
				else {

					anstail->next = new Node(val + carry);
					anstail = anstail->next
				}
				if (check == 1)
				{
					carry = 1;
				}
				else
				{
					carry = 0;
				}

				second = second->next;
			}


		}
		else {
			while (second != NULL) {
				int val =  first->data;
				bool check = 0;
				if (val > 9)
				{
					val -= 10;
					check = 1;
				}
				if (ans == NULL)
				{
					ans = new Node(val);
					anstail = ans;

				}
				else {

					anstail->next = new Node(val + carry);
					anstail = anstail->next
				}
				if (check == 1)
				{
					carry = 1;
				}
				else
				{
					carry = 0;
				}

				first = first->next;
			}
		}
		if (carry == 1)
		{
			anstail->next = new Node( carry);
			anstail = anstail->next
		}
		ans = reverseList(ans);
		return ans;
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
	while (t--)
	{
		int n, m;

		cin >> n;
		Node* first = buildList(n);

		cin >> m;
		Node* second = buildList(m);
		Solution ob;
		Node* res = ob.addTwoLists(first, second);
		printList(res);

	}
	return 0;
}
