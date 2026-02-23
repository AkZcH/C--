#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
  public:
    void bfs(int v, vector<vector<int>> &adj, vector<int>& visited){
      queue<int> q;
      q.push(v);
      visited[v] = 1;

      while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto neighbor : adj[node]){
          if(!visited[neighbor]){
            visited[neighbor] = 1;
            q.push(neighbor);
          }
        }
      }
    }

    int findNumberOfComponent(int V, vector<vector<int>> &edges) {//input is an adjacency matrix
      int result = 0;
      vector<vector<int>>adj(V);

      for(auto &e : edges){ //conversion of matrix to adjacency list
        //since the graph is undirected we need to add edge from u->v and v->u
        int u = e[0];
        int v = e[1];

        adj[v].push_back(u);
        adj[u].push_back(v);
      }
      vector<int> visited(V, 0);

      for(int i=0; i<V; i++){
        if(visited[i] != 1){
          bfs(i, adj, visited);
          result++;
        }
      }

      return result;
    }
};