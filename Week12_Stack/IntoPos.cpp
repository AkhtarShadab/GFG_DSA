#include <bits/stdc++.h>
#include <climits>
#include <string.h>
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()


ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
bool prime(ll a) { if (a == 1) return 0; for (int i = 2; i * i <= a; ++i) if (a % i == 0) return 0; return 1; }
ll binary_exponentiation(ll a, ll b, ll m)
{	ll ans = 1;
	while (b) {
		if (b % 2 == 1)
		{ ans = (ans * a) % m; }
		a = (a * a) % m;
		b /= 2;
	}
	return ans;
}

bool Presi(char a, char b)
{
	if (a == '(') return 1;
	if ((a == '+' or a == '-') and (b == '+' or b == '-')) return 0;
	if ((a == '*' or a == '/') and  (b == '*' or b == '/')) return 0;
	if ((a == '+' or a == '-') && (b == '*' or b == '/')) return 1;
	if ((a == '*' or a == '/') and (b == '^') ) return 1;
	if ((a == '+' or a == '-') and b == '^')return 1;
	return 0;

}

string infixToPostfix(string s) {
	// Your code here
	string ans;
	stack<char> st;
	int n = s.size();
	f(i, 0, n) {

		if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/' or s[i] == '^')
		{

			while (st.empty() != 1 and Presi(st.top(), s[i]) == 0)
			{

				ans.pb(st.top());
				st.pop();
			}
			st.push(s[i]);
			// cout << 0 << " ";

		}

		else if (s[i] == '(')
		{
			st.push('(');
			// cout << 2 << " ";
		}
		else if (s[i] == ')')
		{
			while (st.top() != '(') {
				ans.pb(st.top());
				st.pop();
			}
			st.pop();
			// cout << 3 << " ";
		}
		else {
			ans.pb(s[i]);
			// cout << 1 << " ";
		}
	}
	while (st.empty() != 1)
	{
		ans.pb(st.top());
		st.pop();
	}
	return ans;
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int test_cases;
	cin >> test_cases;
	while (test_cases--) {


		string s;
		cin >> s;
		cout << infixToPostfix(s);

	}
	return 0;
}
