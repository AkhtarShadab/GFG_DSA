#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
class RadixSort
{
public:
	int getMax(int arr[], int n)
	{
		int ans = arr[0];
		for (int i = 1; i < n; ++i)
		{
			if (arr[i] > ans)
				ans = arr[i];
		}
		return ans;
	}
	void CountingSort(int arr[], int n, int exp)
	{
		int output[n];
		int i, count[10] = {0};
		for (int i = 0; i < n; ++i)
		{
			count[(arr[i] / exp) % 10]++;
		}
		for (int i = 1; i < 10; ++i)
		{
			count[i] += count[i - 1];
		}
		for (int i = n - 1; i >= 0; --i)
		{
			output[count[(arr[i] / exp) % 10] - 1] = arr[i];
			count[(arr[i] / exp) % 10]--;
		}

		for (int i = 0; i < n; ++i)
		{
			arr[i] = output[i];
		}
	}
	void Radixsort(int arr[], int n)
	{
		int maxi = getMax(arr, n);
		for (int exp = 1; maxi / exp > 0; exp *= 10)
		{
			CountingSort(arr, n, exp);
		}

	}

};

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
		RadixSort ob;
		ob.Radixsort(arr, n);
		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << " ";
		}

	}
	return 0;
}
