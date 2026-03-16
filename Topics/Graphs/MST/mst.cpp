#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
       vector<int> visited(V, 0);
       int sum = 0;

       priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        >pq;
        pq.push({0, 0});

    while(!pq.empty()){
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if(visited[node]) continue;
        visited[node] = 1;
        sum += weight;
        for(auto it : adj[node]){
            int neighbor = it[0];
            int edWt = it[1];

            if(visited[neighbor]) continue;
            pq.push({neighbor, edWt});
        }
    }

    return sum;
    }
};