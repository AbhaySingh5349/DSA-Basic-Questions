#include <vector>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> a, int target) {
	int n=a.size();
	vector<vector<int>> ans;
	for(int i=0;i<n-3;i++){
		for(int j=i+1;j<n-2;j++){
			for(int k=j+1;k<n-1;k++){
				for(int l=k+1;l<n;l++){
					int x=a[i]+a[j]+a[k]+a[l];
					if(x==target){
						vector<int> v;
						v.push_back(a[i]);
						v.push_back(a[j]);
						v.push_back(a[k]);
						v.push_back(a[l]);

						ans.push_back(v);
					}
				}
			}
		}
	}
  return ans;
}
