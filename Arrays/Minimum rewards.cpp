// Question: Given scores of exam, rewards are given such that person with better score w.r.t adjecent person, should have more score, find min. rewards 
"scores": [8, 4, 2, 1, 3, 6, 7, 9, 5]
op: 25 // [4,3,2,1,2,3,4,5,1]

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
