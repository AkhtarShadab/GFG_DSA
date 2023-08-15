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
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
	Node* temp = head;
	int i = 0;
	while (temp) {
		arr[i] = temp;
		i++;
		temp = temp->next;
	}
}

bool check(Node ** before, Node **after, int num, int K)
{
	if (K > num)
		return 1;

	bool f = true;

	for (int i = 0; i < num; i++) {
		if ((i == K - 1) || (i == num - K)) {
			if (!((before[K - 1] == after[num - K]) && (before[num - K] == after[K - 1]))) f = 0;
		}
		else {
			if (before[i] != after[i]) f = 0;
		}
	}

	return f;
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
		int num, K , firstdata;
		cin >> num >> K;
		int temp;
		cin >> firstdata;
		Node* head = new Node(firstdata);
		Node* tail = head;
		for (int i = 0; i < num - 1; i++) {
			cin >> temp;
			tail->next = new Node(temp);
			tail = tail->next;
		}

		Node *before[num];
		addressstore(before, head);

		head = swapkthnode(head, num, K);

		Node *after[num];
		addressstore(after, head);

		if (check(before, after, num, K))
			cout << 1 << endl;
		else
			cout << 0 << endl;

	}
	return 0;
}

Node *swapkthnode(Node* head, int num, int K)
{
	// Your Code here

	if (K > num) return head;
	if (K == num - K + 1) return head;
	if (K == 2) {
		Node *temp = head->next;
		head->next = NULL;
		temp->next = head;
		return head = temp;

	}
	Node *start = head, *end = head;
	int pos = 1;
	while (1) {
		if (pos < K - 1) start = start->next;
		if (pos < num - K) end = end->next;
		if (pos > K && pos > num - K) break;
		pos++;
	}
	if (K == 1)
	{
		Node *temp1 = start->next;
		Node *temp2 = end->next;
		end->next = start;
		start->next = NULL;
		start = temp2;
		start->next = temp1;
		return head = start;
	}
	if (K == num)
	{

		Node *temp1 = start->next;
		Node *temp2 = end->next;
		start->next = end;
		end->next = NULL;
		end = temp1;
		end->next = temp2;
		return head = end;

	}
	if (start->next == end)
	{
		start->next = end->next;
		Node *temp = end->next;
		end->next = end->next->next;
		temp->next = end;
		return head;
	}
	if (end->next == start)
	{
		end->next = start->next;
		Node *temp = start->next;
		start->next = start->next->next;
		temp->next = start;
		return head;
	}
	Node *temp1 = start->next;
	Node *temp2 = end->next;
	Node *temp3 = temp1->next;
	Node *temp4 = temp2->next;
	start->next = temp2;
	end->next = temp1;
	temp1->next = temp4;
	temp2->next = temp3;
	return head;
}

