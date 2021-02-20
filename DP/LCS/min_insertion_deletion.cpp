/*
 * X="HEAP" Y="PEA"
 * 
 * HEAP - HP + P = PEA
 * 
 *  To convert from X -> Y
 * Deletion = X - LCS
 * Insertion = Y- LCS 
 * 
 */



#include<bits/stdc++.h>
using namespace std;

int lcs(string X, string Y, int X_len , int Y_len)
{
	vector<vector<int>> dp(X_len+1, vector<int>(Y_len+1, 0));
	
	for(int i=0; i<=X_len; i++)
	{
		for(int j=0; j<=Y_len; j++)
		{
			if(i==0 || j==0)
			dp[i][j]=0; 
			else if(X[i-1]==Y[j-1])
			dp[i][j]=1+dp[i-1][j-1];
			else
			dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[X_len][Y_len];
	}

int main()
{
	string X="HEAP";
	string Y="PEA";
	
	int X_len=X.size();
	int Y_len=Y.size();
	int LCS = lcs(X, Y, X_len, Y_len);
	cout<<"Minimum Insertion : "<<Y_len - LCS<<endl;
	cout<<"Minimum Deletion : "<<X_len - LCS<<endl; 
	return 0;
}
