     
// if there exist a Bridge-edge, so graph is not 2-edge connected
// Tree-edges(can be a Bridge-edge): connects new vertices in DFS
// Back-edge: edge b/t current child <--> ancestor with less arrival time than parent
// Back-edge tell us there is another way to reach current vertex from ancestral vertex
// for each existing Tree-edge pair in DFS, we need to check:
// --> if we can reach from parent to child taking some other path than current direct edge
// --> if any of descendents of child can reach parent, we can say parent--child is not Bridge-edge 
// (minimum arrival time of ancestor that current vertex can access)

// Forward-edge: vertex which is our visited descendent with > arrival time

// we will return min arrival time from descendent
// for any vertex, if min arrival time of child > arrival time of parent, so this vertex forms Bridge-edge with child
    
#include <vector>
using namespace std;

bool dfs(vector<vector<int>> &adj_list,int src,int parent,int &time,vector<int> &arrivalTime,vector<int> &minArrivalTime){
  arrivalTime[src] = minArrivalTime[src] = time;
  time++;
  
  for(int child : adj_list[src]){
    if(child==parent) continue;
    
    if(arrivalTime[child] == -1){ // Tree-edge (new edge in dfs traversal)
      if(dfs(adj_list,child,src,time,arrivalTime,minArrivalTime) == false) return false;
      
      if(minArrivalTime[child] == arrivalTime[child]) return false;
    }
    minArrivalTime[src]=min(minArrivalTime[src],minArrivalTime[child]);
  }

  return true;
} 

bool twoEdgeConnectedGraph(vector<vector<int>> adj_list) {
  int n=edges.size();

  if(n==0) return true;
  
  vector<int> arrivalTime(n,-1), minArrivalTime(n,-1); // minimum arrival time of ancestor that child can access
  int time=0;
  
  bool valid = dfs(adj_list,0,-1,time,arrivalTime,minArrivalTime);

  if(valid){
    for(int t : arrivalTime){
      if(t == -1) return false;
    }
  }

  return valid;
}
