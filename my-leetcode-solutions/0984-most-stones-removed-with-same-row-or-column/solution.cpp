class DisjointSet{
public:
    vector<int> parent, rank, size;

    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for(int i=0; i<n;i++){
            parent[i] = i;
        }
    }

    int findPar(int u){
        if(parent[u] == u) return u;
        return parent[u] = findPar(parent[u]);
    }

    bool find(int u, int v) {
        return findPar(u) == findPar(v);
    }

    void unionByRank(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv) return;
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    void unionBySize(int u, int v) {
       int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv) return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu]+= size[pv];
        }
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRows = 0;
        int maxCols = 0;
        int n = stones.size();
        for(auto it : stones){
            maxRows = max(maxRows, it[0]);
            maxCols = max(maxCols, it[1]);
        }
    DisjointSet ds(maxRows + maxCols + 2);
    unordered_map<int, int>mp;

    for(auto it : stones){
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRows + 1;
        ds.unionBySize(nodeRow, nodeCol);
        mp[nodeRow] = 1;
        mp[nodeCol] = 1;
    }

    int count=0;
    for(auto it : mp){
        if(ds.findPar(it.first) == it.first){
            count++;
        }
    }

    return n - count;

    }
};
