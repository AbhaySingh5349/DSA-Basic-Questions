#include <vector>
using namespace std;

// Approach 1: O(n^3)

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

// Approach 2: O(n^2)

#include <vector>
using namespace std;

void twosum(vector<vector<int>> &ans, vector<int> &a, int target, int idx, int val){
	int n=a.size();
	int i=idx, j=n-1;
	while(i<j){
		int x=a[i]+a[j];
		if(x>target){
			j--;
		}else if(x<target){
			i++;
		}else{
			vector<int> v;
			v.push_back(val);
			v.push_back(a[i]);
			v.push_back(a[j]);
			
			ans.push_back(v);
			i++, j--;
		}
	}
}

vector<vector<int>> threeNumberSum(vector<int> a, int target) {
  int n=a.size();
  vector<vector<int>> ans;
	sort(a.begin(),a.end());
	for(int i=0;i<n-2;i++){
		twosum(ans,a,target-a[i],i+1, a[i]);
	}
  return ans;
}
