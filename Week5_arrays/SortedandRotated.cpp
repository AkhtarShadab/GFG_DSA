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
bool SortedCheck(int arr[], int N, char a)
{
	if (a == 'a')
	{
		for (int i = 1; i < N; ++i)
		{
			if (arr[i] < arr[i - 1]) return 0;
		}
		return 1;
	}
	for (int i = 1; i < N; ++i)
	{
		if (arr[i] > arr[i - 1]) return 0;
	}
	return 1;


}
bool shiftByK(int *arr, int N, int k, char a)
{
	int temp[N];
	for (int i = 0; i < k; ++i)
	{
		temp[i] = arr[i];
	}
	for (int i = k; i < N; ++i)
	{
		arr[i - k] = arr[i];
	}
	for (int i = 0; i < k; ++i)
	{
		arr[N - k + i] = temp[i];
	}

	return SortedCheck(arr, N, a);
}
bool checkRotatedAndSorted(int arr[], int num)
{
	int count = 0;
	for (int i = 1; i < num; ++i)
	{
		if (arr[i] > arr[i - 1]) count++;
	}
	if (count != num - 2 && count != 1)
		return 0;
	int maxi = INT_MIN, mini = INT_MAX;
	for (int i = 0; i < num; ++i)
	{
		if (arr[i] > maxi)
			maxi = arr[i];
		if (arr[i] < mini)
			mini = arr[i];
	}
	int maxind, minind;
	for (int i = 0; i < num; ++i)
	{
		if (arr[i] == maxi) maxind = i;
		if (arr[i] == mini) minind = i;
	}

	if (count == num - 2 && maxind < minind) {
		return shiftByK(arr, num, minind, 'a');
	}
	else return shiftByK(arr, num, maxind, 'd');

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
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		cout << checkRotatedAndSorted(arr, n);
	}
	return 0;
}
