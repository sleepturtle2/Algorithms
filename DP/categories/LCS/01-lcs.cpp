/* X= "abcdgh"
 * Y= "abedfh"
 *
 * Longest subsequence = "abdh" //non-contiguous but sequential
 * Longest substring = "ab" //contiguous
 *
 */
//practice link
//https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

int lcs_recursive(string X, string Y, int X_len, int Y_len)
{
	if (X_len == 0 || Y_len == 0)
		return 0; //if any one of 0 length, common length = 0
	else if (X[X_len - 1] == Y[Y_len - 1])
		return 1 + lcs_recursive(X, Y, X_len - 1, Y_len - 1); //if it is a match, increase subseq length by 1 and search in the remaining strings of both
	else																										// not a match
		return max(lcs_recursive(X, Y, X_len - 1, Y_len), lcs_recursive(X, Y, X_len, Y_len - 1));
}

int lcs_memo(vector<vector<int>> &dp, string X, string Y, int X_len, int Y_len)
{
	//cout<<X_len<<" "<<Y_len<<" "<<dp[X_len-1][Y_len-1]<<"\n";

	if (X_len == 0 || Y_len == 0)
		return 0;

	if (dp[X_len - 1][Y_len - 1] != -1)
		return dp[X_len - 1][Y_len - 1];

	if (X[X_len - 1] == Y[Y_len - 1])
		return dp[X_len - 1][Y_len - 1] = 1 + lcs_memo(dp, X, Y, X_len - 1, Y_len - 1);

	else
		return dp[X_len - 1][Y_len - 1] = max(lcs_memo(dp, X, Y, X_len, Y_len - 1), lcs_memo(dp, X, Y, X_len - 1, Y_len));
}

int lcs_tab(string X, string Y, int X_len, int Y_len)
{
	vector<vector<int>> dp(X_len + 1, vector<int>(Y_len + 1));

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
		}
	}
	return dp[X_len][Y_len];
}

int main()
{
	string X = "abcdgh";
	string Y = "abedfhr";

	int len_X = X.size();
	int len_Y = Y.size();

	cout << "Recursive: " << lcs_recursive(X, Y, len_X, len_Y) << endl; //recursive

	vector<vector<int>> dp(len_X, vector<int>(len_Y, -1));

	lcs_memo(dp, X, Y, len_X, len_Y);
	cout << "Memoization: " << dp[len_X - 1][len_Y - 1] << endl;

	cout << "Tabulation: " << lcs_tab(X, Y, len_X, len_Y) << endl;

	return 0;
}
