#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
struct Job
{
	int id;	 // Job Id
	int dead; // Deadline of job
	int profit; // Profit if job is over before or on deadline
};
class Solution
{
public:
	//Function to find the maximum profit and the number of jobs done.
	static bool cmp1(Job &a, Job &b)
	{
		return a.profit > b.profit;
	}
	vector<int> JobScheduling(Job arr[], int n)
	{
		// your code here

		sort(arr, arr + n, cmp1);
		// for (int i = 0; i < n; ++i)
		// {
		// 	cout << arr[i].id << " " << arr[i].dead << " " << arr[i].profit << endl;
		// }
		int m = arr[0].dead;
		for (int i = 1; i < n; ++i)
		{
			if (arr[i].dead > m)
			{
				m = arr[i].dead;
			}
		}
		// cout << m;
		vector<int> a(m + 1, -1);

		vector<int> ans(2, 0);

		for (int i = 0; i < n; ++i)
		{
			for (int j = arr[i].dead; j > 0; j--)
			{
				if (a[j] == -1)
				{
					a[j] = arr[i].id;
					ans[0]++;
					ans[1] += arr[i].profit;
					break;
				}

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
	while (t--) {
		int n;

		//size of array
		cin >> n;
		Job arr[n];

		//adding id, deadline, profit
		for (int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			arr[i].id = x;
			arr[i].dead = y;
			arr[i].profit = z;
		}
		Solution ob;
		//function call
		vector<int> ans = ob.JobScheduling(arr, n);
		cout << ans[0] << " " << ans[1] << endl;
	}
	return 0;
}
