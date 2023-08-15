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
	//Function to find largest rectangular area possible in a given histogram.
	long long getMaxArea(long long arr[], int n)
	{
		// Your code here
		stack<int> s;
		vector<int> ps, ns;
		s.push(0);
		ps.push_back(-1);
		ns.push_back(n);
		for (int i = 1; i < n; i++)
		{
			while (s.empty() != 1 && arr[s.top()] >= arr[i])
			{
				s.pop();
			}
			int check = s.empty() ? -1 : s.top();
			s.push(i);
			ps.push_back(check);
		}
		while (s.empty() == 0)
			s.pop();
		s.push(n - 1);
		for (int i = n - 2; i > -1; i--)
		{
			while (s.empty() != 1 && arr[s.top()] >= arr[i])
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
		for (int i = 0; i < n; i++)
		{
			cout << ps[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < n; ++i)
		{
			cout << ns[i] << " ";
		}
		long long ans = 0;
		for (int i = 0; i < n; ++i)
		{

			ans = max(ans, (ns[i] - ps[i] - 1) * arr[i]);
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

		long long arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		Solution ob;
		cout << ob.getMaxArea(arr, n) << endl;
	}
	return 0;
}
