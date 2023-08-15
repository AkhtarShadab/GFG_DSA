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
bool isSubSequence(string A, string B)
{
	//code here
	if (A.size() < B.size()) return false;

	int j = 0;
	for (int i = 0; i < B.size(); ++i)
	{
		if (B[i] == A[j]) {
			j++;

		}

	}
	if (j == A.size()) return true;
	return false;
}
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
		string s1, s2;
		cin >> s1;
		getchar();
		cin >> s2;
		isSubSequence(s1, s2);
	}
	return 0;
}
