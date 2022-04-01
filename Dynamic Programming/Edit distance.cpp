// Approach 1:

#include <bits/stdc++.h>
using namespace std;

int solve(string s1, string s2, int n, int m, vector<vector<int>>& memo){
	if(n==0) return m;
	if(m==0) return n;
	
	if(memo[n][m]!=-1) return memo[n][m];
	
	if(s1[n-1]==s2[m-1]){
		return memo[n][m]=solve(s1,s2,n-1,m-1,memo);
	}else{
		int x=solve(s1,s2,n,m-1,memo); // insert
		int y=solve(s1,s2,n-1,m,memo); // delete
		int z=solve(s1,s2,n-1,m-1,memo); // substitute
		
		return memo[n][m]=1+min(z,min(x,y));
	}
}

int levenshteinDistance(string s1, string s2) {
  int n=s1.length(), m=s2.length();
	vector<vector<int>> memo(n+1,vector<int> (m+1,-1));
  return solve(s1,s2,n,m,memo);
}

// Approach 2:

using namespace std;

int levenshteinDistance(string s1, string s2) {
  int n=s1.length(), m=s2.length();
	int dp[n+1][m+1];
	
	for(int i=0;i<n+1;i++) dp[i][0]=i;
	for(int j=1;j<m+1;j++) dp[0][j]=j;
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
			}
		}
	}
  return dp[n][m];
}
