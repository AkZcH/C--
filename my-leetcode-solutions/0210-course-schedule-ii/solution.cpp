class Solution {
public:
    bool dfs(int v, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited, stack<int>& st){
        visited[v] = 1;
        pathVisited[v] = 1;
        
        for(auto it : adj[v]){
            if(!visited[it]){
                if(dfs(it, adj, visited, pathVisited, st) == true) return true;
            }
            else if(pathVisited[it]){
                return true;
            }

        }
        pathVisited[v] = 0;
        st.push(v);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> visited(n, 0);
        vector<int> pathVisited(n, 0);
        vector<vector<int>> adj(n);
        stack<int> st;

        for(auto p : prerequisites){
            int course = p[0];
            int prereq = p[1];

            adj[prereq].push_back(course);
         }

        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, pathVisited, st)) return {};
            }
        }

        vector<int> result;

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};
