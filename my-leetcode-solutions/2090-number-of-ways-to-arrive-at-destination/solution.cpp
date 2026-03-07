class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>>adj(n);
        const long long mod = 1e9 + 7;

        for(auto it : roads){
            int u =  it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        vector<long long>ways(n, 0);
        ways[0] = 1;

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        >pq;

        pq.push({0, 0});

        while(!pq.empty()){
            int node = pq.top().second;
            long cost = pq.top().first;
            pq.pop();

            for(auto iter : adj[node]){
                int v = iter.first;
                int wt = iter.second;

                if(dist[v] > wt + cost){
                    dist[v] = wt + cost;
                    pq.push({dist[v], v});
                    ways[v] = ways[node];
                }

                else if(dist[v] == wt + cost){
                    ways[v] = (ways[v] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
