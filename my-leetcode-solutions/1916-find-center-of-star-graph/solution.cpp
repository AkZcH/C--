class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> distance(n+1, 0);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            distance[u]++;
            distance[v]++;
        }
        int conn = 0;
        for(int i=1; i<=n; i++){
            if(distance[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};
