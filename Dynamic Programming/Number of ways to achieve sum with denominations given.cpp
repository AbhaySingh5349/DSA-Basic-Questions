// Approach 1:

#include <vector>
using namespace std;

int solve(vector<int>& coins, int n, int target, vector<vector<int>>& memo){
	if(target==0) return 1;
	if(n==0 || target<0) return 0;
	
	if(memo[n][target]!=-1) return memo[n][target];
	
	int x=solve(coins,n,target-coins[n-1],memo); // using coin multiple times
	int y=solve(coins,n-1,target,memo); // not using current coin
	
	return memo[n][target]=x+y;
}

int numberOfWaysToMakeChange(int target, vector<int> coins) {
  int n=coins.size();
	vector<vector<int>> memo( n+1 , vector<int> (target+1, -1));
	return solve(coins,n,target,memo);
}

// Approach 2:

#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int target, vector<int> coins) {
  int n=coins.size();
	int dp[n+1][target+1];
	
	for(int i=0,j=0;i<n+1;i++) dp[i][j]=1;
	for(int i=0,j=1;j<target+1;j++) dp[i][j]=0;
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<target+1;j++){
			dp[i][j]=dp[i-1][j];
			if(j-coins[i-1]>=0) dp[i][j]+=dp[i][j-coins[i-1]];
		}
	}
  return dp[n][target];
}
