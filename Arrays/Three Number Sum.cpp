#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> a, int target) {
	int n=a.size();
  vector<vector<int>> ans;
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				int sum=a[i]+a[j]+a[k];
				if(sum==target){
					vector<int> v;
					v.push_back(a[i]);
					v.push_back(a[j]);
					v.push_back(a[k]);
					
					sort(v.begin(),v.end());
					ans.push_back(v);
				}
			}
		}
	}
	sort(ans.begin(),ans.end());
  return ans;
}
