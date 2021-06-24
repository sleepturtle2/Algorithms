#include<bits/stdc++.h>
using namespace std;

void print(vector<char>&res)
{
	for(int i=0; i<(int)res.size(); i++)
	cout<<res[i];
	cout<<"\n";
}

void print_lcs(string X, string Y, int X_len, int Y_len)
{
	vector<vector<int>>dp(X_len+1, vector<int>(Y_len+1, 0));
	//build table 
	for(int i=0; i<=X_len;i++)
	{
		for(int j=0; j<=Y_len;j++)
		{
			if(i==0 || j==0)
			dp[i][j]=0;
			
			else if(X[i-1]==Y[j-1])
			dp[i][j]=1+dp[i-1][j-1];
			else 
			dp[i][j]=max(dp[i-1][j], dp[i][j-1]);	
		}
	}
	
	int index=dp[X_len][Y_len];
	vector<char> lcs(index);
	int i=X_len; int j=Y_len;
	while(i>0 && j>0)
	{
		
		if(X[i-1]==Y[j-1])
		{
			lcs[index-1]=X[i-1];
			i--;
			j--;
			index--;
		}
		else
		{
			if(dp[i][j-1]>dp[i-1][j])
			j--;
			else
			i--;
		}
	}
	print(lcs);
}

int main()
{	string X="acbcf";
	string Y="abcdaf";
	
	int X_len=X.size();
	int Y_len=Y.size();
	
	print_lcs(X, Y, X_len, Y_len);
	return 0;
}
