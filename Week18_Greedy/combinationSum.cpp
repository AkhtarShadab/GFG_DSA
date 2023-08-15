#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
class Solution {
public:
	//Function to return a list of indexes denoting the required
	//combinations whose sum is equal to given number.
	void recur(vector<int> &A, int B, vector<vector<int>> &ans, vector<int> &travese, int l)
	{

		if (B == 0) {
			ans.push_back(travese);
			return;
		}
		for (int i = l; i < A.size(); ++i)
		{
			travese.push_back(A[i]);
			int val = B - A[i];
			if (val < 0) {travese.pop_back(); return;}
			recur(A, val, ans, travese, i);
			travese.pop_back();
		}

	}
	vector<vector<int> > combinationSum(vector<int> &A, int B) {
		// Your code here
		sort(A.begin(), A.end());
		A.erase(unique(A.begin(), A.end()), A.end());
		vector<vector<int>> ans;
		vector<int> check;
		recur(A, B, ans, check, 0);
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
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> A;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			A.push_back(x);
		}
		int sum;
		cin >> sum;
		Solution ob;
		vector<vector<int>> result = ob.combinationSum(A, sum);
		if (result.size() == 0) {
			cout << "Empty";
		}
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
