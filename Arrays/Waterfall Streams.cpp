// Question: given 2d array with 0=empty space (water can fall downwards) , 1=water split 50-50 to left and right. Find %water in last row for each column
"array": [
    [0, 0, 0, 0, 0, 0, 0],
    [1, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0, 0],
    [1, 1, 1, 0, 0, 1, 0],
    [0, 0, 0, 0, 0, 0, 1],
    [0, 0, 0, 0, 0, 0, 0]
  ],
  "source": 3
}
op: [0,0,0,25,25,0,0]

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
