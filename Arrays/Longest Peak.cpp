"array": [1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3]
op: 6 // 0,10,6,5,-1,-3

// Approach 1:

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

// Approach 2:

using namespace std;

int longestPeak(vector<int> a) {
  int n=a.size();
	int i=1;
	int maxlen=0;
	while(i<n-1){
		bool isPeak = (a[i]>a[i-1] && a[i]>a[i+1]);
		if(isPeak){
			int left=i-1;
			while(left>=0 && a[left]<a[left+1]) left--;
			
			int right=i+1;
			while(right<n && a[right]<a[right-1]) right++;
			
			int len=right-left-1;
			maxlen=max(maxlen,len);
			
			i=right-1;
		}else{
			i++;
		}
	}
  return (maxlen<3 ? 0:maxlen);
}
