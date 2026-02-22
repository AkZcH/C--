#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool dfs(int node, vector<int> adj[], vector<int>& visited, vector<int>& pathVisited){
        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto neighbor : adj[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor, adj, visited, pathVisited) == true) return true;
            }
            else if(pathVisited[neighbor]){
                return true;
            }
        }
        pathVisited[node] = 0;
        return false;
    }

    bool isCyclic(int N, vector<int> adj[]) {
        vector<int> visited(N, 0);
        vector<int> pathVisited(N, 0);

        for(int i=0; i<N; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, pathVisited) == true) return true;
            }
        }
        return false;
    }
};
