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

class Solution
{
public:
	//Function to find maximum of minimums of every window size.
	vector <int> maxOfMin(int arr[], int n)
	{
		// Your code here

		vector<int> ans(n), ns, ps;
		stack<int> s;
		s.push(n - 1);
		ns.push_back(n);
		for (int i = n - 2; i > -1; --i)
		{
			while (s.empty() != 1 and arr[i] <= arr[s.top()])
			{
				s.pop();
			}
			int check = s.empty() ? n : s.top();
			s.push(i);
			ns.push_back(check);
		}
		for (int i = 0; i < n / 2; i++)
		{
			swap(ns[i], ns[n - 1 - i]);
		}
		// for (int i = 0; i < n; ++i)
		// {
		// 	cout << ns[i] << " ";
		// }
		while (s.empty() != 1) s.pop();
		ps.push_back(-1);
		s.push(0);
		for (int i = 1; i < n; ++i)
		{
			while (s.empty() != 1 and arr[i] <= arr[s.top()])
			{
				s.pop();
			}
			int check = s.empty() ? -1 : s.top();
			s.push(i);
			ps.push_back(check);
		}
		// cout << endl;
		// for (int i = 0; i < n; ++i)
		// {
		// 	cout << ps[i] << " ";
		// }
		// cout << endl;
		for (int i = 0; i < n; ++i)
		{
			ns[i] = ns[i] - ps[i] - 1;
		}
		for (int i = 0; i < n; ++i)
		{
			if (ans[ns[i] - 1] != 0) {
				if (ans[ns[i] - 1] < arr[i]) ans[ns[i] - 1] = arr[i];
			}
			else ans[ns[i] - 1] = arr[i];
		}
		for (int i = n - 2; i > -1; --i)
		{
			if (ans[i] < ans[i + 1])
			{
				ans[i] = ans[i + 1];
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
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		Solution ob;
		vector <int> res = ob.maxOfMin(a, n);
		for (int i : res) cout << i << " ";
		cout << endl;

	}
	return 0;
}
