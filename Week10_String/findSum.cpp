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
int findSum(string str)
{

	// Your code here
	vector<string> v;
	string check;
	for (int i = 0; i < str.size(); ++i)
	{

		while (str[i] - '0' > -1 && str[i] - '0' < 10 && i < str.size()) {
			check.push_back(str[i]);
			i++;
		}
		if (check.size() != 0) v.push_back(check);
		check = "";
	}
	int sum = 0;
	for (auto& X : v)
	{
		sum += stoi(X);
	}
	return sum;

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
		string s;
		cin >> s;
		cout << findSum(s);

	}
	return 0;
}
