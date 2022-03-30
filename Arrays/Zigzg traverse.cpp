"array": [
    [1, 3, 4, 10],
    [2, 5, 9, 11],
    [6, 8, 12, 15],
    [7, 13, 14, 16]
  ]
op: [1,2,3,....,15,16]

// Approach 1:

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

// Approach 2:

#include <vector>
using namespace std;

vector<int> zigzagTraverse(vector<vector<int>> mat) {
  int n=mat.size(), m=mat[0].size();
	vector<int> ans(n*m);
	int row=0, col=0, dir=0;
	for(int i=0;i<n*m;i++){
		ans[i]=mat[row][col];
		if(dir==0){
			if(row==n-1){
				col++;
				dir=1;
			}else if(col==0){
				row++;
				dir=1;
			}else{
				row++;
				col--;
			}
		}else{
			if(col==m-1){
				row++;
				dir=0;
			}else if(row==0){
				col++;
				dir=0;
			}else{
				row--;
				col++;
			}
		}
	}
  return ans;
}
