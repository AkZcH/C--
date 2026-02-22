//wap to print all the terminal nodes of a DAG

#include<iostream>
#include<vector>
using namespace std;

vector<int> terminalNodes(vector<vector<int>>& graph){ //adjacency list
	int n = graph.size();
	vector<int> result;

	for(int i=0; i<n; i++){
		if(graph[i].empty()){
			result.push_back(i);
		}
	}

	return result;
}