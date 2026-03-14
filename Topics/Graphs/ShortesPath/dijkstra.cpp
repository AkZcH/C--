#include<iostream>
#include<vector>
#include<queue>
using namespace std;    

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int, int>>adj[V];
        vector<int> distance(V);
        
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        >pq;
            
        //making the graph
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({wt, v});
            adj[v].push_back({wt, u});
        }
        
        for(int i=0; i<V; i++){
            distance[i] = 1e9;
        }
        distance[src]=0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            if(d > distance[node]) continue;
            
            for(auto it : adj[node]){
                int v = it.second;
                int wt = it.first;
                
                if(distance[v] > d + wt){
                    distance[v] = d + wt;
                    pq.push({distance[v], v});
                }
            }
        }

        
        return distance;
        
        
    }
};