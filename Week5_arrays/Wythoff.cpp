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
bool wythoff(int a , int b) {
	if (a > b) swap(a, b);
	int k = b - a;
	float d = 1 + sqrt(5);
	// cout << d << endl;
	d /= 2;
	d *= k;
	int temp = (int)d;
	// cout << temp << endl;
	if (temp == a) return false;
	return true;
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
		int a, b;
		cin >> a >> b;
		cout << wythoff(a, b) << endl;	// True if Hot state
	}
	return 0;
}
