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

bool divAndSub(int N) {
	// code here
	if (N == 1) return false;
	else if (N > 1 && N < 6) return true;
	else if (N == 6 || N == 7) return false;
	bool arr[N + 1];
	arr[0] = false;
	arr[1] = true;
	arr[2] = true;
	arr[3] = true;
	arr[4] = true;
	arr[5] = true;
	arr[6] = false;
	arr[7] = false;
	for (int i = 8; i < N + 1; ++i)
	{
		if (arr[i / 5] == 0 || arr[i / 4] == 0 || arr[i / 3] == 0 || arr[i / 2] == 0)
		{
			arr[i] = 1;
		}
		else if (arr[i - 5] == 0 || arr[i - 4] == 0 || arr[i - 3] == 0 || arr[i - 2] == 0)
		{
			arr[i] = 1;
		}
		else arr[i] = 0;
	}
	// for (int i = 0; i < N + 1; ++i)
	// {
	// 	cout << arr[i] << endl;
	// }
	return arr[N];



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
		int N;
		cin >> N;
		bool check = divAndSub(N);
		if (check == true) cout << "Jon" << endl;
		else cout << "Arya" << endl;
	}
	return 0;
}
