class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n+1, 0);
        vector<int>outdegree(n+1, 0);
        int judge = -1;

        for(auto &tr : trust){
            int u = tr[0];
            int v = tr[1];

            outdegree[u]++;
            indegree[v]++;
        }

        for(int i=0 ;i<=n; i++){
            if(outdegree[i] == 0 && indegree[i] == n-1) judge = i;
        }

        return judge;
    }
};
