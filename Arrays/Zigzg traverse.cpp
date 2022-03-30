#include <vector>
using namespace std;

vector<int> zigzagTraverse(vector<vector<int>> mat) {
  int n=mat.size(), m=mat[0].size();
	
	vector<int> v[n+m-1];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int idx=i+j;
			v[idx].push_back(mat[i][j]);
		}
	}
	vector<int> ans;
	for(int i=0;i<n+m-1;i++){
		vector<int> row=v[i];
		if(i%2==0){
			ans.insert(ans.end(),row.begin(),row.end());
		}else{
			reverse(row.begin(),row.end());
			ans.insert(ans.end(),row.begin(),row.end());
		}
	}
  return ans;
}
