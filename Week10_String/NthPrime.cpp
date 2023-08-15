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
int primeDigits(int n)
{
	//code here
	queue<string> q;
	q.push("2");
	q.push("3");
	q.push("5");
	q.push("7");
	string check;
	while (n--)
	{
		check = q.front();
		q.push(check + "2");
		q.push(check + "3");
		q.push(check + "5");
		q.push(check + "7");
		q.pop();
	}
	int ans = stoi(check);
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
		cout << primeDigits(n);
	}
	return 0;
}
