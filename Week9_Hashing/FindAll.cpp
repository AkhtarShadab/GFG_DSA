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
void findAll()
{
	queue<int> q;
	unordered_set< int> st;
	q.push(1);
	q.push(2);
	q.push(3);
	while (q.front() < 100000000) {
		string curr = to_string(q.front());
		st.insert(stoi(curr));
		q.pop();
		q.push(stoi(curr + "1"));
		q.push(stoi(curr + "2"));
		q.push(stoi(curr + "3"));

	}
	for (auto& X : st) {
		cout << X << endl;
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
		findAll();
	}
	return 0;
}
