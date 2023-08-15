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
int subArraySum(int arr[], int n, int sum)
{
	//Your code here
	unordered_map<int, int> mp;
	int count = 0;
	int currsum = 0;
	for (int i = 0; i < n; ++i)
	{
		currsum += arr[i];
		if (currsum == sum) count++;
		if (mp[currsum - sum] > 0 )count += mp[currsum - sum];
		mp[currsum]++;

	}
	return count;


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
		int sum;
		cin >> sum;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		cout << subArraySum(arr, n, sum);

	}
	return 0;
}
