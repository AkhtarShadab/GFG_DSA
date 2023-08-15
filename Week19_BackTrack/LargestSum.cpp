#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;

class Solution
{
public:
	//Function to return the largest possible number of n digits
	//with sum equal to given sum.
	string largestNumber(int n, int sum)
	{
		// Your code here
		if (9 * n < sum) return "-1";
		int i = 9;
		int j  = 0;
		string res;
		while (j != n)
		{
			if (sum >= i )
			{
				sum -= i;
				res.push_back(i + '0');
				j++;
			}
			else if (sum != 0)
			{
				i--;
			}
			else {
				res.push_back('0');
				j++;
			}
		}
		return res;
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
		int n, sum;
		cin >> n >> sum;

		Solution obj;
		//function call
		cout << obj.largestNumber(n, sum) << endl;

	}
	return 0;
}
