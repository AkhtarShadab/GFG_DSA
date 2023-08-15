#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
	/*You are required to complete this method */
	int dp[101][101];
	bool f(string A, string B, string C, int i, int j, int k)
	{
		bool flag1 = false;
		bool flag2 = false;

		if (k == C.size()) return true;
		if (dp[i][j] != -1) return dp[i][j];
		if (i < A.size() )
		{
			if (A[i] == C[k]) flag1 = f(A, B, C, i + 1, j, k + 1);
		}
		if (j < B.size())
		{
			if (B[j] == C[k]) flag2 = f(A, B, C, i, j + 1, k + 1);
		}

		bool flag3 = flag2 | flag1;
		return dp[i][j] = flag3;

	}
	bool isInterleave(string A, string B, string C)
	{
		//Your code here
		memset(dp, -1, sizeof(dp));
		return f(A, B, C, 0, 0, 0);

	}

};

//{ Driver Code Starts.
int main() {
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		string a, b, c;
		cin >> a;
		cin >> b;
		cin >> c;
		Solution obj;
		cout << obj.isInterleave(a, b, c) << endl;
	}
	// your code goes here
	return 0;
}