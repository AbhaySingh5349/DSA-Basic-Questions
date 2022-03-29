#include <vector>
using namespace std;

int minRewards(vector<int> a) {
  int n=a.size();
	int rewards[n];
	rewards[0]=1;
	for(int i=1;i<n;i++){
		rewards[i]=1;
		if(a[i]>a[i-1]){
			rewards[i]=rewards[i-1]+1;
		}else{
			for(int j=i-1;j>=0;j--){
				if(a[j]>=a[j+1]) rewards[j]=max(rewards[j],rewards[j+1]+1);
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++) ans+=rewards[i];
  return ans;
}
