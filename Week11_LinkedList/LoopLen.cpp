#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
// #define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
int countNodesinLoop(struct Node *head)
{
	// Code here
	Node *slow, *fast;
	slow = head->next;
	fast = head->next->next;
	while (slow != fast)
	{
		if (fast == NULL || fast->next == NULL) return 0;
		slow = slow->next;
		fast = fast->next->next;

	}
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	int count = 0;
	fast = fast->next;
	while (slow != fast)
	{
		count++;
		fast = fast->next;
	}
	return count + 1;

}
void loopHere(Node* head, Node* tail, int position)
{
	if (position == 0) return;

	Node* walk = head;
	for (int i = 1; i < position; i++)
		walk = walk->next;
	tail->next = walk;
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
		int n, num;
		cin >> n;

		Node *head, *tail;
		cin >> num;
		head = tail = new Node(num);

		for (int i = 0 ; i < n - 1 ; i++)
		{
			cin >> num;
			tail->next = new Node(num);
			tail = tail->next;
		}

		int pos;
		cin >> pos;
		loopHere(head, tail, pos);

		cout << countNodesinLoop(head) << endl;
	}
	return 0;
}

