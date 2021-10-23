#include <vector>
using namespace std;

bool cycleInGraph(vector<vector<int>> edges) {
  int n=edges.size();
	vector<int> graph[n];
	vector<int> indegree(n,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<edges[i].size();j++){
			int v=edges[i][j];
			graph[i].push_back(v);
			indegree[v]++;
		}
	}
	
	queue<int> q;
	for(int i=0;i<n;i++){
		if(indegree[i]==0) q.push(i);
	}
	int c=0;
	while(q.size()>0){
		int u=q.front();
		q.pop();
		c++;
		for(int i=0;i<graph[u].size();i++){
			int v=graph[u][i];
			indegree[v]--;
			if(indegree[v]==0) q.push(v);
		}
	}
  return !(c==n);
}
