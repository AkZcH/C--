class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& visited, int node){
        visited[node] = 1;

        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(adj, visited,it);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int c = connections.size();
        if(c < n - 1) return -1;
        int ans = -1;

        vector<vector<int>>adj(n);

        for(auto &it : connections){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans++;
                dfs(adj, visited, i);
            }
        }
        return ans;
    }
};
