class Solution {
public:
    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& colored){
        colored[node] = color;

        for(auto it : graph[node]){
            if(colored[it] == -1){
                if(dfs(it, !color, graph, colored) == false) return false;
            }
            else if(colored[it] == color){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colored(n, -1);

        for(int i=0; i<n; i++){
            if(colored[i] == -1){
                if(dfs(i, 0, graph, colored) == false) return false;
            }
        }

        return true;
    }
};
