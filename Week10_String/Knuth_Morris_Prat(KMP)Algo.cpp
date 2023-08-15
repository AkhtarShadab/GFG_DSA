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

// Function to fill lps[] for given patttern pat[0..M-1]
// LPS - Longest proper prefix suffix array.
void computeLPSArray(string pat, int M, int* lps)
{
	// Your code here
	int len = 0;
	lps[len] = 0;
	int i = 1;
	while (i < M)
	{
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if (len == 0) {
				lps[i] = 0;
				i++;
			}
			else {
				len = lps[len - 1];
			}
		}
	}

}

// Function to check if the pattern exists in the string or not.
void KMPSearch(string pat, string txt)
{
	// Your code here
	int n = txt.size();
	int m = pat.size();
	int lps[m];
	computeLPSArray(pat, m, lps);

	int j = 0, i = 0;
	while (i < n)
	{
		if (pat[j] == txt[i]) {
			i++;
			j++;
		}
		// cout << i << " " << j << endl;
		if (j == m)
		{
			cout << i - j << endl;
			j = lps[j - 1];
		}

		else if (i < n && txt[i] != pat[j])
		{
			if (j == 0) i++;
			else {
				j = lps[j - 1];
			}
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
		string txt, pat;
		cin >> txt;
		getchar();
		cin >> pat;
		KMPSearch(pat, txt);

	}
	return 0;
}
