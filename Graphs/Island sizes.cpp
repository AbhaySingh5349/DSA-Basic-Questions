#include <vector>
using namespace std;

int dfs(vector<vector<int>> &grid, int n, int m, int i, int j){
	if(i<0 || j<0 || i==n || j==m || grid[i][j]==0) return 0;
	
	grid[i][j]=0;
	int left=dfs(grid,n,m,i,j-1);
	int right=dfs(grid,n,m,i,j+1);
	int up=dfs(grid,n,m,i-1,j);
	int down=dfs(grid,n,m,i+1,j);
	
	return left+right+up+down+1;
}

vector<int> riverSizes(vector<vector<int>> grid) {
  int n=grid.size(), m=grid[0].size();
	int id=2;
	vector<int> v;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]==1){
				int c=dfs(grid,n,m,i,j);;
				v.push_back(c);
			}
		}
	}
  return v;
}
