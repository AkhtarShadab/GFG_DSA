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
bool TripletSum(int arr[], int n, int x)
{
	sort(arr, arr + n);
	for (int i = 0; i < n - 2; ++i)
	{
		int ptr1 = i + 1, ptr2 = n - 1;
		while (ptr1 < ptr2)
		{
			if (arr[ptr1] + arr[ptr2] == x - arr[i]) return 1;
			else if (arr[ptr1] + arr[ptr2] < x - arr[i]) ptr1++;
			else ptr2--;
		}
	}
	return 0;

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
		int n, x;
		cin >> n >> x;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		cout << TripletSum(arr, n, x);
	}
	return 0;
}
