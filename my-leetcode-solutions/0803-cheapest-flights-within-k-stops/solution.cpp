class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>>adj[n];

        for(int i=0; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int>distance(n, 1e9);
        distance[src] = 0;

        queue<pair<int, pair<int, int>>>q;
        q.push({0, {src, 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stops > k )  continue;

            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;

                if(cost + wt < distance[v] && stops <= k){
                    distance[v] = cost + wt;
                    q.push({stops+1, {v, distance[v]}});
                }
            }
        }

        if(distance[dst] == 1e9) return -1;
        return distance[dst];
    }
};
