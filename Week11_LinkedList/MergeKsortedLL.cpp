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
	Node* next;

	Node(int x) {
		data = x;
		next = NULL;
	}

};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout << endl;
}

Node* sortedMerge(Node* head1, Node* head2)
{
	// code here
	Node *start = NULL;
	if (head1->data < head2->data)
	{
		start = head1;
		head1 = head1->next;

	}
	else {
		start = head2;
		head2 = head2->next;
	}

	Node *tail = start;


	while (head1 != NULL and head2 != NULL)
	{
		if (head1->data < head2->data)
		{
			tail->next = head1;
			tail = head1;
			head1 = head1->next;
		}
		else {
			tail->next = head2;
			tail = head2;
			head2 = head2->next;
		}
	}
	while (head1 != NULL)
	{
		tail->next = head1;
		tail = head1;
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		tail->next = head2;
		tail = head2;
		head2 = head2->next;

	}


	return start;
}
class Solution {
public:
	//Function to merge K sorted linked list.
	Node * mergeKLists(Node *arr[], int K)
	{
		// Your code here
		int last = K - 1;
		while (last != 0)
		{
			int i = 0, j = last;
			while (i < j)
			{
				arr[i] = sortedMerge(arr[i], arr[j]);
				i++;
				j--;
				if (i >= j) last = j;
			}
		}
		return arr[0];

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
		int N;
		cin >> N;
		struct Node *arr[N];
		for (int j = 0; j < N; j++)
		{
			int n;
			cin >> n;

			int x;
			cin >> x;
			arr[j] = new Node(x);
			Node *curr = arr[j];
			n--;

			for (int i = 0; i < n; i++)
			{
				cin >> x;
				Node *temp = new Node(x);
				curr->next = temp;
				curr = temp;
			}
		}
		Solution obj;
		Node *res = obj.mergeKLists(arr, N);
		printList(res);

	}
	return 0;
}
