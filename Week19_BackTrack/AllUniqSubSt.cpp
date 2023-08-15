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
	//Function to find all possible unique subsets.



	void recur(int n, vector<vector<int>> &arr, vector<int> &check, vector<int> ans, int l)
	{
		if (l == n)
		{
			arr.push_back(check);
			return;
		}
		else
		{
			check.push_back(ans[l]);
			recur(n, arr, check, ans, l + 1);
			check.pop_back();
			while (l + 1 < n and ans[l] == ans[l + 1]) l++;
			recur(n, arr, check, ans, l + 1);

		}
	}
	vector<vector<int> > AllSubsets(vector<int> arr, int n)
	{
		// code here

		sort(arr.begin(), arr.end());
		vector<vector<int>> ans;
		vector<int> check;

		recur(n, ans, check, arr, 0);
		sort(ans.begin(), ans.end());
		return ans;
	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int t;
	cin >> t; while (t--) {
		int n;
		cin >> n;
		vector<int> A;
		int x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			A.push_back(x);
		}
		Solution obj;
		vector<vector<int> > result = obj.AllSubsets(A, n);
		// printing the output
		for (int i = 0; i < result.size(); i++) {
			cout << '(';
			for (int j = 0; j < result[i].size(); j++) {
				cout << result[i][j];
				if (j < result[i].size() - 1)
					cout << " ";
			}
			cout << ")";
		}
		cout << "\n";
	}
	return 0;
}
