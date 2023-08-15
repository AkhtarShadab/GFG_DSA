#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
struct MinHeap {
	int *harr;
	int capacity;
	int heap_size;

	// Constructor for Min Heap
	MinHeap(int c) {
		heap_size = 0;
		capacity = c;
		harr = new int[c];
	}

	~MinHeap() { delete[] harr; }

	int parent(int i) { return (i - 1) / 2; }

	int left(int i) { return (2 * i + 1); }

	int right(int i) { return (2 * i + 2); }

	void MinHeapify(int); // Implemented in user editor
	int extractMin();
	void decreaseKey(int i, int new_val);
	void deleteKey(int i);
	void insertKey(int k);
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
		ll a;
		cin >> a;
		MinHeap h(a);
		for (ll i = 0; i < a; i++) {
			int c;
			int n;
			cin >> c;
			if (c == 1) {
				cin >> n;

				h.insertKey(n);
			}
			if (c == 2) {
				cin >> n;
				h.deleteKey(n);
			}
			if (c == 3) {
				cout << h.extractMin() << " ";
			}
		}
		cout << endl;
		// delete h.harr;
		h.harr = NULL;

	}
	return 0;
}

int MinHeap::extractMin()
{
	// Your code here
	if (heap_size == 0) return -1;
	int ans = harr[0];
	swap(harr[0], harr[heap_size - 1]);
	heap_size--;
	MinHeapify(0);
	return ans;
}

//Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{
	// Your code here
	if (heap_size <= 0) return;
	if (i >= heap_size) return;
	decreaseKey(i, INT_MIN);
	int check = extractMin();


}

//Function to insert a value in Heap.
void MinHeap::insertKey(int k)
{
	// Your code here

	if (heap_size == capacity) return;
	heap_size++; harr[heap_size - 1] = k;
	int i = heap_size - 1;
	while (i != 0 and harr[i] < harr[parent(i)])
	{
		swap(harr[i], harr[parent(i)]);
		i = parent(i);
	}
}

//Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i]) {
		swap(harr[i], harr[parent(i)]);
		i = parent(i);
	}
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i]) smallest = l;
	if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
	if (smallest != i) {
		swap(harr[i], harr[smallest]);
		MinHeapify(smallest);
	}
}