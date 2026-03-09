class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, int dest){
        if(node == dest) return true;
        visited[node] = 1;
        for(auto it : adj[node]){
            if(!visited[it]){
                if(dfs(it, adj, visited, dest)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);

        return (dfs(source, adj, visited, destination));
    }
};
