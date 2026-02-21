class Solution {
public:
    bool dfs(int v,  vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited){
        visited[v] = 1;
        pathVisited[v] = 1;

        for(auto it : adj[v]){
            if(!visited[it]){
                if(dfs(it, adj, visited, pathVisited)  == true) return true;
            }
            else if(pathVisited[it]){
                return true;
            }
        }
        
        pathVisited[v] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> visited(n, 0);
        vector<int> pathVisited(n, 0);

        vector<vector<int>> adj(n);

        for(auto p : prerequisites){
            int course = p[0];
            int prereq = p[1];

            adj[course].push_back(prereq);
        }

        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, pathVisited) == true) return false;
            }
        }
        return true;
    }
};
