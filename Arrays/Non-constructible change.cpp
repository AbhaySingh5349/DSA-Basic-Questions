#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> a) {
  int n=a.size();
	if(n==0) return 1;
	
  int sum=0;
	for(int i=0;i<n;i++) sum+=a[i];
	
	bool dp[n+1][sum+1];
	for(int i=0,j=0;i<n+1;i++) dp[i][j]=true;
	for(int i=0,j=1;j<sum+1;j++) dp[i][j]=false;
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			dp[i][j]=dp[i-1][j];
			if(j-a[i-1]>=0) dp[i][j]=(dp[i-1][j] || dp[i-1][j-a[i-1]]); 
		}
	}
	
	for(int i=n,j=0;j<sum+1;j++) if(dp[i][j]==false) return j; 
	
	return sum+1;
}
