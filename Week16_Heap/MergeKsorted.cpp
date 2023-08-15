#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
void printArray(vector<int> arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}
typedef struct Triplet {
	int val, apos, pos;
	Triplet(int x, int y, int z )
	{
		val = x;
		apos = y;
		pos = z;
	}
} Triplet;
struct cmp {
	bool operator()(Triplet &a, Triplet &b)
	{
		return a.val > b.val;
	}
};
class Solution
{
public:
	//Function to merge k sorted arrays.
	vector<int> mergeKArrays(vector<vector<int>> arr, int K)
	{
		//code here
		vector<int> ans;
		priority_queue < Triplet, vector<Triplet>, cmp> pq;
		for (int i = 0; i < K; ++i)
		{
			Triplet t(arr[i][0], i, 0);
			pq.push(t);
		}
		while (pq.empty() == 0)
		{
			Triplet t = pq.top();
			pq.pop();
			ans.push_back(t.val);
			int apos = t.apos;
			int pos = t.pos;
			if (arr[apos].size() > ++pos)
			{
				Triplet m(arr[apos][pos], apos, pos);
				pq.push(m);
			}
		}
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
		int k;
		cin >> k;
		vector<vector<int>> arr(k, vector<int> (k, 0));
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++)
			{
				cin >> arr[i][j];
			}
		}
		Solution obj;
		vector<int> output = obj.mergeKArrays(arr, k);
		printArray(output, k * k);
		cout << endl;

	}
	return 0;
}
