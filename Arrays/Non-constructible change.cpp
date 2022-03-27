// Question: minimum sum of money that cannot be created

"coins": [5, 7, 1, 1, 2, 3, 22]
op: 20
	
// Method 1:

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

// Method 2: if current value is > than 'running sum+1' therefor we cannot create that value

#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> a) { 
  int n=a.size();
	if(n==0) return 1;
	int sum=0;
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		if(a[i]>sum+1) return sum+1;
		sum+=a[i];
	}
  return sum+1;
}
