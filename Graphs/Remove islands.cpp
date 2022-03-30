// Question: a valid island is group of horzontally and vertically connected 1s which are not part of border.

"matrix": [
    [1, 0, 0, 0, 0, 0],
    [0, 1, 0, 1, 1, 1],
    [0, 0, 1, 0, 1, 0],
    [1, 1, 0, 0, 1, 0],
    [1, 0, 1, 1, 0, 0],
    [1, 0, 0, 0, 0, 1]
  ]
op: [
    [1, 0, 0, 0, 0, 0],
    [0, 0, 0, 1, 1, 1],
    [0, 0, 0, 0, 1, 0],
    [1, 1, 0, 0, 1, 0],
    [1, 0, 0, 0, 0, 0],
    [1, 0, 0, 0, 0, 1]
  ]

#include <vector>
using namespace std;

void dfs(vector<vector<int>> &grid, int n, int m, int i, int j){
	if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1) return;
	
	grid[i][j]=2;
	dfs(grid,n,m,i,j-1);
	dfs(grid,n,m,i-1,j);
	dfs(grid,n,m,i,j+1);
	dfs(grid,n,m,i+1,j);
}

vector<vector<int>> removeIslands(vector<vector<int>> grid) {
  int n=grid.size(), m=grid[0].size();
	
	// top wall
	for(int i=0,j=0;j<m;j++){
		if(grid[i][j]==1) dfs(grid,n,m,i,j);
	}
	// right wall
	for(int i=1,j=m-1;i<n;i++){
		if(grid[i][j]==1) dfs(grid,n,m,i,j);
	}
	// bottom wall
	for(int i=n-1,j=m-2;j>=0;j--){
		if(grid[i][j]==1) dfs(grid,n,m,i,j);
	}
	// left wall
	for(int i=n-2,j=0;i>=1;i--){
		if(grid[i][j]==1) dfs(grid,n,m,i,j);
	}
	
	for(int i=1;i<n-1;i++){
		for(int j=1;j<m-1;j++){
			if(grid[i][j]==1) grid[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]==2) grid[i][j]=1;
		}
	}
  return grid;
}
