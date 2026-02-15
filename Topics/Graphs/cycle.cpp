#include<iostream>
#include<vector>
#include<queue>
using namespace std;


bool isCycle(vector<vector<int>>graph, int v){
	int n = graph.size();
	vector<int> visited(n, 0);
	queue<pair<int,int>> q;
	q.push({v, -1});
	visited[v] = 1; //mistake(didn't include)

	while(!q.empty()){

		auto [node, parent] = q.front();
		q.pop();

		for(int i=0; i<n; i++){
			if(graph[i][node] == 1){
				if(visited[i] == 0){
                    visited[i] = 1;
                    q.push({i, node});
                }
                else if(i != parent) return true; 
				else{
					visited[i] = 1;
					q.push({i, node});
				}
			}
		}
	}
	return false;
}