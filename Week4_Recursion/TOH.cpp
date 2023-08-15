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
long long TOH(int n, char a, char b, char c)
{
	static int count = 0;

	if (n == 1)
	{
		cout << "Move Disk " << n << " from bar " << a << " to bar " << c << endl;
		count++;
		return count;
	}
	TOH(n - 1, a, c, b);
	cout << "Move Disk " << n << " from bar " << a << " to bar " << c << endl;
	count++;
	TOH(n - 1, b, a, c);
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
		int n, val;
		cin >> n;
		val = TOH(n, 'a', 'b', 'c');
		cout << val;
	}
	return 0;
}
