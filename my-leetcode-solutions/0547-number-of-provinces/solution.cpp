class Solution {
public:
    void bfs(int v, vector<vector<int>>& isConnected, vector<int>& visited){
            queue<int> q;
            q.push(v);
            visited[v] = 1;
            int n = isConnected.size();

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int i=0; i<n; i++){
                    if(isConnected[node][i] == 1 && visited[i] != 1){
                        visited[i] = 1;
                        q.push(i);
                    }
                }
            }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces=0;
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if(visited[i] != 1){
                bfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }
};
