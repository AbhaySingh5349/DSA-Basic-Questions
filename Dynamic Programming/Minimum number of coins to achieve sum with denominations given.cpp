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

