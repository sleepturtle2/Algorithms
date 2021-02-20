/*
 * X= 		AGBCBA 
 * rev(X) = ABCBGA 
 * 
 * find lcs of the two to get the answer 
 */

#include<bits/stdc++.h>
using namespace std;

int lcs(string X, string Y, int len)
{
	vector<vector<int>> dp (len+1, vector<int>(len+1, 0) );
	
	for(int i=0; i<=len ; i++)
	{
		for(int j=0; j<=len; j++)
		{
			if(i==0 || j==0)
			dp[i][j]=0; 
			else if(X[i-1]==Y[j-1])
			dp[i][j]=1+dp[i-1][j-1];
			else 
			dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
		}
	}
	return dp[len][len];
	}
	
string reverse ( string X)
{
	int len = X.size();
	
	int start =0, end=len-1; 
	while(start<end)
	{
		swap(X[start], X[end]);
		start++; 
		end--;
	}
	return X;
}
int main()
{
	
	string X= "AGBCBA"; 
	string Y = reverse(X);
	int len=X.size();
	cout<<lcs(X, Y, len)<<endl;
	return 0;
}
