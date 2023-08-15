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
	while (b)  if (arr[N - 1] == 1) return N;
		else if (arr[0] == 0) return 0;
	int l = 0 , h = N - 1;
	while (l <= h) {
		int mid = (l + h) / 2;
		if (arr[mid] != arr[mid + 1]) return mid + 1;
		else if (arr[mid] == 1 && arr[h] == 0) l = mid + 1;
		else if (arr[h] == 1) return h + 1;
		else h = mid - 1;
	}
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
int count1s(int arr[], int N) {
	if (arr[N - 1] == 1) return N;
	else if (arr[0] == 0) return 0;
	int l = 0 , h = N - 1;
	while (l <= h) {
		int mid = (l + h) / 2;
		if (arr[mid] != arr[mid + 1]) return mid + 1;
		else if (arr[mid] == 1 && arr[h] == 0) l = mid + 1;
		else if (arr[h] == 1) return h + 1;
		else h = mid - 1;
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
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		cout << count1s(a, n);
	}
	return 0;
}
