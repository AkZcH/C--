class Solution {
public:  
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> inDegree(n, 0);
        vector<vector<int>> adjRev(n);
        vector<int> result;
        queue<int> q;

        for(int i=0; i<n; i++){
            for(auto it : graph[i]){
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }

        for(int i=0; i<n; i++){
            if(inDegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);

            for(auto it : adjRev[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }

        sort(result.begin(), result.end());

        return result;
    }
};
