// Question: given array with Distinct elements, find all unique quadruplets 

// Approach 1:

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
					if(x==target) ans.push_back(a[i],a[j],a[k],a[l]);
				}
			}
		}
	}
  return ans;
}

// Approach 2:

#include <vector>
using namespace std;

bool nocommon(int a, int b, int c, int d){
	if(a==c || a==d || b==c || b==d) return false;
	return true;
}

vector<vector<int>> fourNumberSum(vector<int> a, int target) {
  int n=a.size();
	vector<vector<int>> ans;
	map<int,vector<pair<int,int>>> m;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int x=a[i]+a[j];
			int y=target-x;
			
			// this will create permutations of pairs
		/*	if(m.find(y)!=m.end()){
				vector<pair<int,int>> v=m[y];
				for(int k=0;k<v.size();k++){
					pair<int,int> p=v[k];
					if(nocommon(p.first,p.second,a[i],a[j])) ans.push_back({p.first,p.second,a[i],a[j]});
				}
			}
			m[x].push_back({a[i],a[j]}); */
			
			if(m.find(y)!=m.end()){
				vector<pair<int,int>> v=m[y];
				for(int k=0;k<v.size();k++){
					pair<int,int> p=v[k];
					if(nocommon(p.first,p.second,a[i],a[j])) ans.push_back({p.first,p.second,a[i],a[j]});
				}
			}
		}
		for(int k=0;k<i;k++){	
			int x=a[i]+a[k];
			m[x].push_back({a[i],a[k]});
		}
	}
  return ans;
}

// Approach 3:

#include <vector>
using namespace std;

void twosum(vector<vector<int>> &ans, vector<int> &a, int target, int idx, int val2, int val1){
	int n=a.size();
	int i=idx, j=n-1;
	while(i<j){
		int x=a[i]+a[j];
		if(x<target){
			i++;
		}else if(x>target){
			j--;
		}else{
			ans.push_back({val1,val2,a[i],a[j]});
			i++, j--;
		}
	}
}

void threesum(vector<vector<int>> &ans, vector<int> &a, int target, int idx, int val1){
	int n=a.size();
	for(int i=idx;i<n-2;i++){
		twosum(ans,a,target-a[i],i+1,a[i],val1);
	}
}

vector<vector<int>> fourNumberSum(vector<int> a, int target) {
	int n=a.size();
  sort(a.begin(),a.end());
	vector<vector<int>> ans;
	for(int i=0;i<n-3;i++){
		threesum(ans,a,target-a[i],i+1,a[i]);
	}
  return ans;
}
