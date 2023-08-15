#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
class Solution
{
public:
	//Function to find the maximum number of activities that can
	//be performed by a single person.
	static	bool cmp1(pair<int, int> &a, pair<int, int> &b)
	{
		return a.second < b.second;
	}
	int activitySelection(vector<int> start, vector<int> end, int n)
	{
		// Your code here
		vector<pair<int, int>> arr;
		for (int i = 0; i < n; ++i)
		{
			arr.push_back({start[i], end[i]});
		}
		sort(arr.begin(), arr.end(), cmp1);
		int count = 1;
		pair<int, int> p1 = arr[0];
		for (int i = 1; i < n; ++i)
		{
			if (p1.second < arr[i].first)
			{
				p1 = arr[i];
				count++;
			}
		}
		return count;

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
		int n;
		cin >> n;
		vector<int> start(n), end(n);

		//adding elements to arrays start and end
		for (int i = 0; i < n; i++)
			cin >> start[i];
		for (int i = 0; i < n; i++)
			cin >> end[i];
		Solution ob;
		//function call
		cout << ob.activitySelection(start, end, n) << endl;
	}
	return 0;
}
