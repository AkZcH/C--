class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];

        for(int i=0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({wt, v});
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        >pq;

        vector<int>distance(n+1);
        for(int i=1; i<=n; i++) distance[i] = 1e9;
        distance[k] = 0;

        pq.push({0, k});

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

        int ans = 0;

        for(int i=0; i<distance.size(); i++){
            if(distance[i] == 1e9)
        return -1;
            ans = max(ans, distance[i]);
        }

        return ans;
    }
};
