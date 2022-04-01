// Approach 1:

#include <vector>
using namespace std;

int solve(vector<int> coins, int n, int target, vector<vector<int>>& memo){
	 if(target==0) return 0;
	 if(n==0 || target<0) return INT_MAX;
	
	if(memo[n][target]!=-1) return memo[n][target];
	
	int x=solve(coins,n,target-coins[n-1],memo);
	int y=solve(coins,n-1,target,memo);
	
	if(x!=INT_MAX) x+=1;
	
	return memo[n][target]=min(x,y);
}

int minNumberOfCoinsForChange(int target, vector<int> coins) {
  int n=coins.size();
	vector<vector<int>> memo(n+1,vector<int> (target+1,-1));
	int ans=solve(coins,n,target,memo);
	return (ans==INT_MAX ? -1:ans);
}

// Approach 2:

#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int target, vector<int> coins) {
  int n=coins.size();
	int dp[n+1][target+1];
	for(int i=0;i<n+1;i++) dp[i][0]=0;
	for(int j=1;j<target+1;j++) dp[0][j]=target+1;
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<target+1;j++){
			dp[i][j]=dp[i-1][j];
			if(j-coins[i-1]>=0) dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
		} 
	}
  return (dp[n][target]>target ? -1:dp[n][target]);
}
