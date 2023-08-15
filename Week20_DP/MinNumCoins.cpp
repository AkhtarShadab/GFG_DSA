#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Complete this function
long long dp[1001][1001];
class Solution
{
public:
	//Function to find the minimum number of coins to make the change
	//for value using the coins of given denominations.
	long long solve(int coins[], int numberOfCoins, int value)
	{
		if (value == 0) return dp[numberOfCoins][value] = 0;
		if (value < 0 ) return INT_MAX;
		if (numberOfCoins == 0) return dp[numberOfCoins][value] = INT_MAX;
		if (dp[numberOfCoins][value] == -1)
		{
			return dp[numberOfCoins][value] = min(solve(coins, numberOfCoins, value - coins[numberOfCoins - 1]) + 1 ,
			                                      solve(coins, numberOfCoins - 1, value));
		}
		return dp[numberOfCoins][value];
	}
	long long minimumNumberOfCoins(int coins[], int numberOfCoins, int value)
	{
		// your code here
		memset(dp, -1, sizeof(dp));
		long long ans = solve(coins, numberOfCoins, value);
		return {ans == INT_MAX ? -1 : ans};
	}
};





int main() {

	//taking total count of testcases
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int testcases;
	cin >> testcases;
	while (testcases--)
	{
		//taking value
		int value;
		cin >> value;

		//taking number of coins
		int numberOfCoins;
		cin >> numberOfCoins;
		int coins[numberOfCoins];

		//taking value of each coin
		for (int i = 0; i < numberOfCoins; i++)
			cin >> coins[i];
		Solution obj;
		//calling function minimumNumberOfCoins()
		int answer = obj.minimumNumberOfCoins(coins, numberOfCoins, value);

		//printing "Not Possible" if answer is -1
		//else printing answer
		if (answer == -1)
			cout << "Not Possible" << endl;
		else
			cout << answer << endl;

	}
	return 0;
}