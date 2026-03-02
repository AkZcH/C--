class Solution {
public:
    bool dfs(int node, vector<int>& visited, vector<int>& pathVisited, vector<vector<int>>& adj){
        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto it : adj[node]){
            if(!visited[it]){
                if(dfs(it, visited, pathVisited, adj) == true) return true;
            }
            else if(pathVisited[it]) return true;
        }
        pathVisited[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for(auto i : prerequisites){
            int u = i[0];
            int v = i[1];

            adj[v].push_back(u);
        } 

        vector<int> visited(n, 0);
        vector<int> pathVisited(n, 0);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(dfs(i, visited, pathVisited, adj) == true) return false;
            }
        }
        return true;
    }
};
