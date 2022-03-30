"edges": [
    [1, 3],
    [2, 3, 4],
    [0],
    [],
    [2, 5],
    []
  ]
op: true // multiple cycles exist: 0 -> 1 -> 2 -> 0 , 0 -> 1 -> 4 -> 2 -> 0 , 1 -> 2 -> 0 -> 1

// Approach 1: Using Kahn's Algorithm (it gives Topo-sort), if valid Topo-sort doesn't exists, means graph has a Cycle

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

// Approach 2:

#include <vector>
using namespace std;

bool dfs(vector<vector<int>> edges, int src, int parent, vector<bool> &visited, vector<bool> &dfsVisited){
	visited[src]=true, dfsVisited[src]=true;
	for(int child : edges[src]){
		if(visited[child]==false){
			if(dfs(edges,child,src,visited,dfsVisited)) return true;
		}else{
			if(dfsVisited[child]==true) return true;
		}
	}
	dfsVisited[src]=false;
	return false;
}

bool cycleInGraph(vector<vector<int>> edges) {
  int n=edges.size();
	vector<bool> visited(n,false);
	for(int i=0;i<n;i++){
		if(visited[i]==false){
			vector<bool> dfsVisited(n,false);
			if(dfs(edges,i,-1,visited,dfsVisited)) return true;
		}
	}
  return false;
}
