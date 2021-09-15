/*
 * X="abcde"
 * Y="abfce"
 *
 * ans=|"ab"| = 2
 */

//practice link
//https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#

#include <bits/stdc++.h>
using namespace std;

int lc_substring_tab(string X, string Y, int X_len, int Y_len)
{
	vector<vector<int>> dp(X_len + 1, vector<int>(Y_len + 1, 0));
	int result = 0;
	for (int i = 0; i <= X_len; i++)
	{

		for (int j = 0; j <= Y_len; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
				result = max(result, dp[i][j]);
			}
			else
				dp[i][j] = 0;
		}
	}
	/*
	for(int i=0; i<(int)dp.size(); i++)
	{
		for(int j=0; j<(int)dp[0].size(); j++)
		cout<<dp[i][j]<<" ";
		cout<<"\n";
	}*/
	return result;
}

/*
int lc_substring_recursive(string X, string Y, int X_len, int Y_len, int result)

{
	if(X_len==0 || Y_len==0)
	return 0;

	else if(X[X_len-1]==Y[Y_len-1])
	return result=max(result, 1+ lc_substring_recursive(X, Y, X_len-1, Y_len-1, result));
	else
	return 0;
	}
*/

int main()
{
	string X = "abcde";
	string Y = "abfce";

	int X_len = X.size();
	int Y_len = Y.size();

	cout << lc_substring_tab(X, Y, X_len, Y_len) << endl;
	//int result=0;
	//lc_substring_recursive(X, Y, X_len, Y_len, result);
	//cout<<result<<endl;

	return 0;
}
