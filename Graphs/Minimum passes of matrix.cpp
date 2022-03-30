#include <vector>
using namespace std;

int minimumPassesOfMatrix(vector<vector<int>> grid) {
  int n=grid.size(), m=grid[0].size();
	int dxy[4][4]={{-1,0},{0,1},{1,0},{0,-1}};
	queue<pair<int,int>> q;
	int negatives=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]>0) q.push({i,j});
			if(grid[i][j]<0) negatives++;
		}
	}
	int moves=0;
	while(q.size()>0){
		int size=q.size();
		while(size--){
			pair<int,int> p=q.front();
			q.pop();
			int x=p.first, y=p.second;
			
			for(int k=0;k<4;k++){
				int i=x+dxy[k][0], j=y+dxy[k][1];
				if(i>=0 && j>=0 && i<n && j<m && grid[i][j]<0){
					negatives--;
					grid[i][j]*=-1;
					q.push({i,j});
				}
			}
		}
		if(q.size()) moves++;
	}
	
  return (negatives==0 ? moves:-1);
}
