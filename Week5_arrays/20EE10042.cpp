#include <bits/stdc++.h>
using namespace std;

int Naiveum(int a[], int n) {
	for (int i = 1; i < n; ++i)
	{
		a[i] += a[i - 1];
	}
	int sum = INT_MIN;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			sum = max(sum, a[j] - a[i]);
		}
	}
	return sum;
}

int KadanesAlgo(int a[], int n) {
	int maxsf = INT_MIN, maxeh = 0;

	for (int i = 0; i < n; i++) {
		maxeh  += a[i];
		if (maxsf < maxeh)
			maxsf = maxeh;

		if (maxeh < 0)
			maxeh = 0;
	}
	return maxsf;
}


int main()
{

	int n;
	cout << "Write n: ";
	cin >> n;
	int a[n];
	cout << "Write " << n << " number :";
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << "Maximum subarray sum is " << KadanesAlgo(a, n);
	return 0;
}
