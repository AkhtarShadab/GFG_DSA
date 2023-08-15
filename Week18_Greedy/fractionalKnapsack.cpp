#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;

struct Item {
	int value;
	int weight;
};

class Solution
{
public:
	//Function to get the maximum total value in the knapsack.
	static bool cmp(pair<double, int> &a, pair<double, int> &b)
	{
		return a.first > b.first;
	}
	double fractionalKnapsack(int W, Item arr[], int n)
	{
		// Your code here
		vector<pair<double, int>> a;
		for (int i = 0; i < n; ++i)
		{
			double val = (double)arr[i].value / (double)arr[i].weight;
			a.push_back({val, arr[i].weight});
		}
		sort(a.begin(), a.end(), cmp);
		int i = 0;
		double ans = 0;
		while (W != 0 and i < n)
		{
			// cout << W << " " << a[i].first << endl;
			if (a[i].second < W) {
				ans += a[i].first * (double)a[i].second;
				W -= a[i].second;
			}
			else {
				ans += a[i].first * (double)W;
				W = 0;
			}
			i++;
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
	//taking testcases
	cin >> t;
	cout << setprecision(2) << fixed;
	while (t--) {
		//size of array and weight
		int n, W;
		cin >> n >> W;

		Item arr[n];
		//value and weight of each item
		for (int i = 0; i < n; i++) {
			cin >> arr[i].value >> arr[i].weight;
		}

		//function call
		Solution ob;
		cout << ob.fractionalKnapsack(W, arr, n) << endl;
	}
	return 0;
}
