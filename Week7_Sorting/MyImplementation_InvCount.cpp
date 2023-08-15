#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
int sort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);
int mergeSort(int arr[], int size);


int mergeSort(int arr[], int size)
{
	int temp[size];
	return sort(arr, temp, 0, size - 1);

}

int sort(int arr[], int temp[], int left, int right)
{
	cout << left << right << endl;
	int inv_count = 0, mid;
	if (left < right)
	{
		if ((right + left) % 2) mid = (left + right) / 2;
		else mid = (left + right) / 2 ;

		inv_count += sort(arr, temp, left, mid);
		cout << inv_count << endl;
		inv_count += sort(arr, temp, mid + 1, right);
		cout << inv_count << endl;
		inv_count += merge(arr, temp, left, mid + 1, right);
		cout << inv_count << endl;
	}
	return inv_count;
}
int merge(int arr[], int temp[], int left, int mid , int right)
{
	int inv_count = 0, i, j, k;

	i = left;
	j = mid;
	k = left;

	while (i < mid and j <= right)
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
			inv_count += (mid - i);
		}
	}
	while (i < mid)
	{
		temp[k++] = arr[i++];
	}
	while (j <= right)
	{
		temp[k++] = arr[j++];
	}
	for (int m = left; m <= right; ++m)
	{
		arr[m] = temp[m];
	}
	return inv_count;

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
		int ans = mergeSort(arr, n);
		cout << "Sorted Array: ";
		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << "Number of Inversions: " << ans << endl << endl;
	}
	return 0;
}
