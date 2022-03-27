using namespace std;

int longestPeak(vector<int> a) {
  int n=a.size();
	
	int left[n], right[n];
	
	left[0]=1;
	for(int i=1;i<n;i++){
		left[i]=1;
		if(a[i]>a[i-1]) left[i]=max(left[i],left[i-1]+1);
	}
	
	right[n-1]=1;
	for(int i=n-2;i>=0;i--){
		right[i]=1;
		if(a[i]>a[i+1]) right[i]=max(right[i],right[i+1]+1);
	}
	
	int ans=0;
	for(int i=0;i<n;i++){
		if(left[i]>1 && right[i]>1) ans=max(ans,left[i]+right[i]-1);
	}
  return (ans>2 ? ans:0);
}
