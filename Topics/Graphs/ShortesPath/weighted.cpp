#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// User function Template for C++
class Solution {
  public:
    void topoSort(int node, vector<pair<int, int>> adj[], vector<int>& visited, stack<int>& st){
        visited[node] = 1;
        
        for(auto it : adj[node]){
            int v = it.first;
            if(!visited[v]){
                topoSort(v, adj, visited, st);
            }
        }
        st.push(node);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];
        
        for(int i=0; i<E; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
        }
        
        vector<int>visited(V, 0);
        vector<int>distance(V);
        stack<int> st;
        
        for(int i=0; i<V; i++) distance[i] = 1e9;
        distance[0] = 0;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                topoSort(i, adj, visited, st);
            }
        }
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(distance[node] != 1e9 && distance[v] > distance[node] + wt){
                    distance[v] = distance[node] + wt;
                }
            }
        }
        
        for(int i=0; i<V; i++){
            if(distance[i] == 1e9) distance[i] = -1;
        }
        
        return distance;
        
        
    }
};
