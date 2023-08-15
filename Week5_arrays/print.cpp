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
int n;
bool flag  = 0;
void printi(int N, vector<int> &ans)
{
	// cout << N << endl;
	ans.push_back(N);
	if (N == n) {
		return ;
	}
	if (N > 0 ) {
		if (flag == 0)printi(N - 5, ans);
		else printi(N + 5, ans);
	}
	if (N <= 0 && flag == 0) {
		flag = 1;
		printi(N + 5, ans);
	}

}
vector<int> pattern(int N) {
	// code here
	n = N;
	vector<int> ans;
	ans.push_back(N);
	printi(N - 5, ans);
	return ans;

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
		int n;
		cin >> n;
		vector<int> ans = pattern(n);
		for (auto x : ans)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
