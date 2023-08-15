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
vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
{
	//Your code here
	vector<int> ans(hashSize, -1);
	int counter = 0;
	bool check = false;
	for (int i = 0; i < sizeOfArray; ++i)
	{
		if (counter == hashSize) return ans;
		int key = (arr[i]) % hashSize;



		while (ans[key] != -1 && check == false) {

			if (ans[key] == arr[i]) check = true;
			key = (key + 1) % hashSize;

		}
		if (check == true) {
			check = false;
			continue;
		}

		ans[key] = arr[i];
		counter++;
	}
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
		int n, m;
		cin >> m >> n;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		vector<int> ans = linearProbing(m, a, n);
		for (auto& x : ans)
		{
			cout << x << " ";
		}

	}
	return 0;
}
