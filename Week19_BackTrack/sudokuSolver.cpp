#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9
using namespace std;

class Solution
{
public:
	//Function to find a solved Sudoku.
	bool isSafe(int grid[N][N] , int i, int j, int x)
	{
		for (int k = 0; k < N; ++k)
		{
			if (grid[i][k] == x || grid[k][j] == x) return false;
		}
		int s = (int)sqrt(N);
		int rs = i - i % s;
		int cs = j - j % s;
		for (int k = 0; k < s; ++k)
		{
			for (int l = 0; l < s; ++l)
			{
				if (grid[k + rs][l + cs] == x) return false;
			}
		}
		return true;
	}
	bool SolveSudoku(int grid[N][N])
	{
		// Your code here
		int row = -1  , col = -1;
		bool empty = true;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 0) {
					row = i; col  = j;
					empty = false; break;
				}
			}
			if (!empty) break;

		}
		// cout << i << " " << j << endl;
		if (empty) return true;
		for (int k = 1; k < N + 1; ++k)
		{
			if (isSafe(grid, row, col, k))
			{
				grid[row][col] = k;
				if (SolveSudoku(grid)) return true;
				else grid[row][col] = 0;
			}
		}
		return false;
	}

	//Function to print grids of the Sudoku.
	void printGrid (int grid[N][N])
	{
		// Your code here
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}

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
		int grid[N][N];

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				cin >> grid[i][j];
		for (int i = 0; i < 9; i++)
		{	for (int j = 0; j < 9; j++)
			{	cout << grid[i][j] << " ";

			}
			cout << endl;
		}
		cout << endl;
		Solution ob;

		if (ob.SolveSudoku(grid) == true)
			ob.printGrid(grid);
		else
			cout << "No solution exists";

		cout << endl;
	}
	return 0;
}
