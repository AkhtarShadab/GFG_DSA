#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	//Function to find the nth catalan number.
	unsigned long long findCatalan(int n)
	{
		//code here
		unsigned long long cat_ = 1;

		// For the first number


		// Iterate till N
		for (unsigned long long i = 1; i <= n; i++) {
			// Calculate the number
			// and print it
			cat_ *= (4 * i - 2);
			cat_ /= (i + 1);
		}
		return cat_;
	}
};

//{ Driver Code Starts.

int main()
{
	//taking count of testcases
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {

		//taking nth number
		int n;
		cin >> n;
		Solution obj;
		//calling function findCatalan function
		cout << obj.findCatalan(n) << "\n";
	}
	return 0;
}