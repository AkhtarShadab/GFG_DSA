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
vector<int> mergeThree(vector<int> &A, vector<int> &B, vector<int> &C)
{
	int p1 = 0, p2 = 0, p3 = 0;
	vector<int> ans;
	while (p1 < A.size() && p2 < B.size() && p3 < C.size())
	{
		if (A[p1] <= B[p2] && A[p1] <= C[p3]) {
			ans.push_back(A[p1]);
			p1++;
		}
		else if (B[p2] <= A[p1] && B[p2] <= C[p3])
		{
			ans.push_back(B[p2]);
			p2++;
		}
		else if (C[p3] <= A[p1] && B[p2] >= C[p3])
		{
			ans.push_back(C[p3]);
			p3++;
		}
	}
	if (p1 == A.size())
	{
		while (p2 < B.size() && p3 < C.size())
		{
			if (B[p2] <= C[p3]) {
				ans.push_back(B[p2]);
				p2++;
			}
			else {
				ans.push_back(C[p3]);
				p3++;
			}
		}
		if (p2 == B.size()) {
			while (p3 < C.size()) {
				ans.push_back(C[p3]);
				p3++;
			}
		}
		else {
			while (p2 < B.size()) {
				ans.push_back(B[p2]);
				p2++;
			}
		}
	}
	else if (p2 == B.size())
	{
		while (p1 < A.size() && p3 < C.size())
		{
			if (A[p1] <= C[p3]) {
				ans.push_back(A[p1]);
				p1++;
			}
			else {
				ans.push_back(C[p3]);
				p3++;
			}
		}
		if (p1 == A.size()) {
			while (p3 < C.size()) {
				ans.push_back(C[p3]);
				p3++;
			}
		}
		else {
			while (p1 < A.size()) {
				ans.push_back(A[p1]);
				p1++;
			}
		}

	}
	else {
		while (p2 < B.size() && p1 < A.size())
		{
			if (B[p2] <= A[p1]) {
				ans.push_back(B[p2]);
				p2++;
			}
			else {
				ans.push_back(A[p1]);
				p1++;
			}
		}
		if (p2 == B.size()) {
			while (p1 < A.size()) {
				ans.push_back(A[p1]);
				p1++;
			}
		}
		else {
			while (p2 < B.size()) {
				ans.push_back(B[p2]);
				p2++;
			}
		}
	}
	return ans;
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
		int n, m, p;
		cin >> n >> m >> p;
		vector<int> a(n), b(m), c(p);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> b[i];
		}
		for (int i = 0; i < p; ++i)
		{
			cin >> c[i];
		}

		vector<int> ans = mergeThree(a, b, c);
		for (auto x : ans)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
