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

