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
	//Function to find the largest number after k swaps.
	void recur(string &s, int index, int k, string &ans)
	{
		ans = max(ans, s);
		if (k == 0 || index >= s.size())
			return;
		for (int i = index + 1; i < s.size(); i++)
		{
			if (s[index] < s[i])
			{
				swap(s[i], s[index]);
				recur(s, index + 1, k - 1, ans);
				swap(s[i], s[index]);
			}
		}
		recur(s, index + 1, k, ans);
	}
	string findMaximumNum(string str, int k)
	{
		// code here.
		string ans = str;
		recur(str, 0, k, ans);
		return ans;
	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int t, k;
	string str;

	cin >> t;
	while (t--)
	{
		cin >> k >> str;
		Solution ob;
		cout << ob.findMaximumNum(str, k) << endl;
	}
	return 0;
}
