

#include<bits/stdc++.h>
using namespace std;

int LRS(string X, int len)
{
	vector<vector<int>> dp(len+1, vector<int>(len+1, 0));
	for(int i=0; i<=len; i++)
	for(int j=0; j<=len; j++)
	{
		if(i==0 || j==0)
		dp[i][j]=0; 
		else if ( X[i-1]==X[j-1] && i!=j) 
		dp[i][j]=1+dp[i-1][j-1];
		else
		dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
	}
	return dp[len][len];
	}

int main()
{
	string X="AABEBCDD";
	int len=X.size();
	cout<<LRS(X, len)<<endl;
	return 0;
}
