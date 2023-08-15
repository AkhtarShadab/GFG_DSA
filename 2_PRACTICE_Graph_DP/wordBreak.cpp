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

int dp[1101];
class Solution
{
public:
	unordered_set<string> st;
	int f(string a, int i)
	{
		int n =  a.size();
		if (n == 0) return 1;
		if (dp[i] != -1) return dp[i];

		int flag = 0;
		int j;
		for ( j = i; j < n; ++j)
		{
			string check = a.substr(i, j);
			if (st.find(check) != st.end())
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1 and f(a, j) == 1) return dp[i] = 1;
		return dp[i] = 0;
	}
	int wordBreak(string A, vector<string> &B) {
		//code here
		int n = B.size();
		for (int i = 0; i < n; i++)
		{
			st.insert(B[i]);
		}
		return f(A, 0);

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
	{	int n;
		cin >> n;
		vector<string> dict;
		for (int i = 0; i < n; i++) {
			string S;
			cin >> S;
			dict.push_back(S);
		}
		string line;
		cin >> line;
		Solution ob;
		cout << ob.wordBreak(line, dict) << "\n";

	}
	return 0;
}
