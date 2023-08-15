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
int findMedian(int arr[], int n, int brr[], int m)
{
	int begin = 0 , end = n;
	while (begin <= end)
	{
		int i1 = (begin + end) / 2;
		int i2 = (n + m + 1) / 2 - i1;
		int min1 = (i1 == n) ? INT_MAX : arr[i1];
		int max1 = (i1 == 0) ? INT_MIN : arr[i1 - 1];
		int min2 = (i2 == m) ? INT_MAX : brr[i2];
		int max2 = (i2 == 0) ? INT_MIN : brr[i2 - 1];


		if (max1 <= min2 && max2 <= min1) {
			if ((n + m) % 2 == 0) return (max(max1, max2) + min(min1, min2)) / 2;
			else return max(max1, max2);
		}
		else if (max1 > min2) {
			end = i1 - 1;
		}
		else begin = i1 + 1;
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
		cin >> n >> m;
		int arr[n], brr[m];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> brr[i];
		}

		cout << findMedian(arr, n, brr, m);

	}
	return 0;
}
