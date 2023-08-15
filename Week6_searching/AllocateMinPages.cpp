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
bool Possible(int A[], int N, int M, int maxi)
{
	int count = 1;
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		if (sum + A[i] < maxi) {
			sum += A[i];
		}
		else {
			count++;
			sum = A[i];
		}
		if (count > M) return false;
	}
	return true;
}
int MinNumPages(int A[], int N, int M)
{
	int r1 = -1;
	int r2 = 0;
	for (int i = 0; i < N; ++i)
	{
		r1 = max(A[i], r1);
		r2 += A[i];
	}
	int lo = r1, hi = r2;
	// cout << lo << " " << hi << endl;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		// cout << mid << endl;
		if (Possible(A, N, M, mid)) hi = mid - 1;
		else lo = mid + 1;
	}
	if (lo == r1) return lo;
	return hi;
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
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		cout << MinNumPages(arr, n, m) << endl;
	}
	return 0;
}
