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
void QuadraticProbing(vector <int>&hash, int hashSize, int arr[], int N)
{
	//Your code here
	bool check = false;
	for (int i = 0; i < N; ++i)
	{
		int key = (arr[i]) % hashSize;
		int j = 1;
		if (hash[key] == arr[i]) continue;
		while (hash[key] != -1 && check == false)
		{	key = (arr[i]) % hashSize;
			key = (key + j * j) % hashSize;
			if (hash[key] == arr[i]) {
				check = true;
			}
			j++;
		}
		if (check == true)
		{
			check = false;
			continue;
		}
		hash[key] = arr[i];
	}

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
		int n, m;
		cin >> m >> n;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		vector<int> ans(m, -1) ;
		QuadraticProbing(ans, m, a, n);
		for (auto& x : ans)
		{
			cout << x << " ";
		}

	}
	return 0;
}
