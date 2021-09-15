/* string A="AGGTAB"
 * string B="GXTXAYB"
 *
 * ans= | A "G" X G "T" X "A" Y "B" |
 * 		= 9
 * Observation:
 * The common part is the LCS. The rest are the mutually exclusive parts.
 * Thus, length = |a| + |b| - |LCS|
 */

//practice link
//https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

#include <bits/stdc++.h>
using namespace std;

int lcs(string X, string Y, int X_len, int Y_len)
{
	vector<vector<int>> dp(X_len + 1, vector<int>(Y_len + 1, 0));

	for (int i = 0; i <= X_len; i++)
	{
		for (int j = 0; j <= Y_len; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

			//cout<<dp[i][j]<<" ";
		}
	}
	return dp[X_len][Y_len];
}

int main()
{
	string X = "AGGTAB";
	string Y = "GXTXAYB";

	int X_len = X.size();
	int Y_len = Y.size();

	cout << X_len + Y_len - lcs(X, Y, X_len, Y_len) << endl;
	return 0;
}
