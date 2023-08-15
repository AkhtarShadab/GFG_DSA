#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;

void CycleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int item = arr[i];
		int pos = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < item)
				pos++;

		}
		if (pos == i) continue;
		while (item == arr[pos]) pos++;
		swap(item, arr[pos]);
		while (pos != i)
		{
			pos = i;
			for (int j = i + 1; j < n; ++j)
			{
				if (arr[j] < item)
					pos++;
			}
			while (item == arr[pos]) pos++;
			swap(item, arr[pos]);

		}
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
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		CycleSort(arr, n);
		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << " ";
		}

	}
	return 0;
}
