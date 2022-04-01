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
