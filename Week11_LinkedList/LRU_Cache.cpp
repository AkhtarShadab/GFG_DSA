#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;

class Node {
public:
	int key;
	int value;
	Node *pre;
	Node *next;


	Node(int k, int v)
	{
		key = k;
		value = v;
		pre = NULL; next = NULL;
	}
};


class LRUCache
{
private:
	unordered_map<int, Node*> mp;
	int capacity, count;
	Node *head, *tail;

public:
	//Constructor for initializing the cache capacity with the given value.

	LRUCache(int cap)
	{
		// code here
		capacity = cap;
		head = new Node(0, 0);
		tail = new Node(0, 0);
		head->next = tail;
		tail->pre = head;
		head->pre = NULL;
		tail->next = NULL;
		count = 0;
	}

	void deleteNode(Node *node)
	{
		node->pre->next = node->next;
		node->next->pre = node->pre;
	}

	void addToHead(Node *node)
	{
		node->next = head->next;
		node->next->pre = node;
		node->pre = head;
		head->next = node;
	}

	//Function to return value corresponding to the key.
	int GET(int key)
	{
		// your code here
		if (mp[key] != NULL)
		{
			Node *temp = mp[key];
			int result = temp->value;
			deleteNode(temp);
			addToHead(temp);
			return result;
		}
		return -1;
	}

	//Function for storing key-value pair.
	void SET(int key, int value)
	{
		// your code here
		if (mp[key] != NULL)
		{
			Node *temp = mp[key];
			temp->value = value;
			deleteNode(temp);
			addToHead(temp);
		}
		else {
			Node *temp = new Node(key, value);
			mp[key] = temp;
			if (count < capacity)
			{
				count++;
				addToHead(temp);
			}
			else
			{
				mp.erase(tail->pre->key);
				deleteNode(tail->pre);
				addToHead(temp);
			}

		}
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
		int capacity;
		cin >> capacity;
		LRUCache *cache = new LRUCache(capacity);

		int queries;
		cin >> queries;
		while (queries--)
		{
			string q;
			cin >> q;
			if (q == "SET")
			{
				int key;
				cin >> key;
				int value;
				cin >> value;
				cache->SET(key, value);
			}
			else
			{
				int key;
				cin >> key;
				cout << cache->GET(key) << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
