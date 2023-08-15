#include <bits/stdc++.h>
using namespace std;

// Structure of node of the tree
struct node {
	int sum, prefixsum, suffixsum, maxsum;
};

// A Max of 1000 Node Array
node tree[4 * 1000];

// Utility funciton to build the tree
void build(int arr[], int low, int high, int index)
{
	if (low == high) {
		tree[index].sum = arr[low];
		tree[index].prefixsum = arr[low];
		tree[index].suffixsum = arr[low];
		tree[index].maxsum = arr[low];
	} else {
		int mid = (low + high) / 2;
		build(arr, low, mid, 2 * index + 1);
		build(arr, mid + 1, high, 2 * index + 2);
		tree[index].sum = tree[2 * index + 1].sum + tree[2 * index + 2].sum;
		tree[index].prefixsum = max(tree[2 * index + 1].prefixsum, tree[2 * index + 1].sum + tree[2 * index + 2].prefixsum);
		tree[index].suffixsum = max(tree[2 * index + 2].suffixsum, tree[2 * index + 2].sum + tree[2 * index + 1].suffixsum);
		tree[index].maxsum = max(tree[index].prefixsum, max(tree[index].suffixsum, max(tree[2 * index + 1].maxsum, max(tree[2 * index + 2].maxsum, tree[2 * index + 1].suffixsum + tree[2 * index + 2].prefixsum))));
	}
}


// } Driver Code Ends
//User function Template for C++
int getMid(int ss, int se)
{
	return ss + (se - ss) / 2;
}
//Function to update a value in input array and segment tree.
void updateUTIL(int ss, int se, int si, int index, int value, int arr[])
{
	if (index > se or index < ss) return;
	if (ss == se)
	{
		tree[si].prefixsum = tree[si].suffixsum = tree[si].maxsum = tree[si].sum = value;
		return;
	}
	int mid = getMid(ss, se);

	updateUTIL(ss, mid, 2 * si + 1, index, value, arr);
	updateUTIL(mid + 1, se, 2 * si + 2, index, value, arr);
	tree[si].sum = tree[2 * si + 1].sum + tree[2 * si + 2].sum;
	tree[si].prefixsum = max(tree[2 * si + 1].prefixsum, tree[2 * si + 1].sum + tree[2 * si + 2].prefixsum);
	tree[si].suffixsum = max(tree[2 * si + 2].suffixsum, tree[2 * si + 2].sum + tree[2 * si + 1].suffixsum);
	tree[si].maxsum = max(tree[si].prefixsum, max(tree[si].suffixsum, max(tree[2 * si + 1].maxsum, max(tree[2 * si + 2].maxsum, tree[2 * si + 1].suffixsum + tree[2 * si + 2].prefixsum))));

}
void update(int arr[], int arrSize, int index, int value)
{
	// code here
	arr[index - 1] = value;
	updateUTIL(0, arrSize - 1, 0, index - 1, value, arr);
}


//Funciton to return the Maximum-Sum in the range
node RangeMaxSum(int l, int r, int ss, int se, int si, int arr[])
{

	node result;
	result.sum = result.maxsum = result.prefixsum = result.suffixsum = INT_MIN;

	if (l > se or r < ss) return result;
	if (l <= ss and r >= se) return tree[si];

	int mid = getMid(ss, se);
	if (l > mid)
	{
		return RangeMaxSum(l, r, mid + 1, se, 2 * si + 2, arr);;
	}
	else if (r <= mid) return RangeMaxSum(l, r, ss, mid, 2 * si + 1, arr);
	node left = RangeMaxSum(l, r, ss, mid, 2 * si + 1, arr);
	node right = RangeMaxSum(l, r, mid + 1, se, 2 * si + 2, arr);

	result.sum = left.sum + right.sum;
	result.prefixsum = max(left.prefixsum, left.sum + right.prefixsum);
	result.suffixsum = max(right.suffixsum, right.sum + left.suffixsum);
	result.maxsum = max(result.prefixsum,
	                    max(result.suffixsum,
	                        max(left.maxsum,
	                            max(right.maxsum,
	                                left.suffixsum + right.prefixsum))));

	return result;
}
int query(int arr[], int n, int l, int r)
{
	// code here
	return RangeMaxSum(l - 1, r - 1, 0, n - 1, 0, arr).maxsum;
}
//{ Driver Code Starts.

// Driver Code
int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	while (T--)
	{
		int n, q, index, value, left, right, type;
		int* arr = NULL;
		cin >> n >> q;
		arr = new int[n];
		for (int i = 0; i < n; i++)cin >> arr[i];
		build(arr, 0, n - 1, 0);
		for (int i = 0; i < q; i++) {
			cin >> type;
			if (type == 1) {
				cin >> left >> right;
				cout << query(arr, n, left, right) << endl;
			} else {
				cin >> index >> value;
				update(arr, n, index, value);
			}
		}
		delete [] arr;
		arr = NULL;
	}
	return 0;
}