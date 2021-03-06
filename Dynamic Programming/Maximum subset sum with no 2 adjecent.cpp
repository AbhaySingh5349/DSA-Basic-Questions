// Approach 1:

#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> a) {
  int n=a.size();
	if(n==0) return 0;
	
	int dp[n];
	dp[0]=a[0];
	dp[1]=max(a[0],a[1]);
	for(int i=2;i<n;i++){
		dp[i]=max(dp[i-1],a[i]+dp[i-2]);
	}
  return dp[n-1];
}

// Approach 2:

#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> a) {
  int n=a.size();
	if(n==0) return 0;
	if(n==1) return a[0];
	
	int preprev=a[0];
	int prev=max(a[0],a[1]);
	int ans=max(prev,preprev);
	for(int i=2;i<n;i++){
		int cur=max(prev,a[i]+preprev);
		preprev=prev;
		prev=cur;
		ans=cur;
	}
	return ans;
}
