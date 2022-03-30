#include <vector>
using namespace std;

// O(m^2 * n)

void dfs(vector<vector<double>> grid, int n, int m, int i, int j, vector<double> &ans, double percentage){	
	if(j<0 || j>=m || grid[i][j]==1) return;
	
	while(i<n && grid[i][j]==0) i++;
	if(i==n){
		ans[j]+=percentage; // water can fall into a bucket from multiple sources
		return;
	}
	
	i--;
	int x=j, y=j;
	// left movement
	while(x>=0 && grid[i][x]==0 && grid[i+1][x]==1) x--;
	dfs(grid,n,m,i,x,ans,percentage/2.0);
	
	// right movement
	while(y<m && grid[i][y]==0 && grid[i+1][y]==1) y++;
	dfs(grid,n,m,i,y,ans,percentage/2.0);
}

vector<double> waterfallStreams(vector<vector<double>> grid, int src) {
	int n=grid.size(), m=grid[0].size();
  vector<double> ans(m,0);
	dfs(grid,n,m,0,src,ans,100.0);
  return ans;
}
