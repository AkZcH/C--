#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node, vector<int>& colored, int color, vector<vector<int>>& graph){
	colored[node] == color;

	for(auto it : graph[node]){
		if(colored[it] == -1){
			if(dfs(it, colored, !color, graph) == false) return false;
		}
		else if(colored[it] == color) return false;
	}
	return true;
}

bool isBipartite(vector<vector<int>>& graph){
	int n = graph.size();
	vector<int> colored(n, -1);

	for(int i=0; i<n; i++){
		if(colored[i] == -1){
			if(dfs(i, colored, 0, graph) == false) return false;
		}
	}
	return true;
}