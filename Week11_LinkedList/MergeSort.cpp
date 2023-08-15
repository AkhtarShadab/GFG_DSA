#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
// #define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
struct Node
{
	int data;
	struct Node *next, *prev;

	Node (int x) {
		data = x;
		next = NULL;
		prev = NULL;
	}
};

struct Node *merge(struct Node *a, struct Node *b)
{
	if (a == NULL)return b;
	if (b == NULL)return a;
	Node *head = NULL, *tail = NULL;
	if (a->data <= b->data) {
		a->prev = tail;
		head = tail = a;
		a = a->next;
	}
	else {
		b->prev = tail;
		head = tail = b;
		b = b->next;
	}
	while (a != NULL && b != NULL) {
		if (a->data <= b->data) {
			tail->next = a;
			a->prev = tail;
			tail = a;
			a = a->next;
		}
		else {

			tail->next = b;
			b->prev = tail;
			tail = b;
			b = b->next;
		}
	}
	if (a == NULL) {tail->next = b; b->prev = tail;}
	else {
		tail->next = a;
		a->prev = tail;
	}
	return head;

}

struct Node *sortDoubly(struct Node *head)
{
	// Your code here
	if (head->next == NULL || head == NULL) return head;
	Node *prev = NULL;
	Node *slow = head;
	Node *fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	prev = slow->prev;
	slow->prev = NULL;
	prev->next = NULL;
	head = sortDoubly(head);
	slow = sortDoubly(slow);
	head = merge(head, slow);
	return head;
}


//{ Driver Code Starts.

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout << head->data << ' ';
		temp = head;
		head = head->next;
	}
	cout << endl;
	while (temp)
	{
		cout << temp->data << ' ';
		temp = temp->prev;
	}
	cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
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
		int n, tmp;
		struct Node *head = NULL;
		cin >> n;
		while (n--) {
			cin >> tmp;
			insert(&head, tmp);
		}
		head = sortDoubly(head);
		print(head);

	}
	return 0;
}
