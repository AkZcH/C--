#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int v, vector<vector<int>>& isConnected, vector<int>& visited){
    queue<int> q;
    q.push(v); //push the given node
    visited[v] = 1; //mark the node visited
    int n = isConnected.size(); //no. of nodes

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=0; i<n; i++){
            if(isConnected[node][i] == 1 && visited[i] != 1){ //got a neighbour that is unvisited
                visited[i] = 1; //mark it as visited
                q.push(i); //push the neighbour
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
