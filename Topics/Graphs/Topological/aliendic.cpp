#include<iostream>.
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
	vector<int> topoSort(vector<vector<int>>& adj, int n){
		vector<int> inDegree(n, 0);
		queue<int> q;
		for(int i=0; i<n; i++){
			for(auto it : adj[i]){
				inDegree[it]++;
			}
		}

		for(int i=0; i<n; i++){
			if(inDegree[i] == 0) q.push(i);
		}

		vector<int> topo;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			topo.push_back(node);
			for(auto it : adj[node]){
				inDegree[it]--;
				if(inDegree[it] == 0) q.push(it);
			}
		}
		return topo;
	}

	string findOrder(string dict[], int N, int K) {
		vector<vector<int>> adj(K);
		for(int i=0; i<N-1; i++){
			string s1 = dict[i];
			string s2 = dict[i+1];
			int n = min(s1.size(), s2.size());
			for(int j=0; j<n; j++){
				if(s1[j] != s2[j]){
					adj[s1[j] - 'a'].push_back(s2[j] - 'a');
					break;
				}
			}
		}

		vector<int> topo = topoSort(adj, K);
		string result = "";

		for(auto it : topo){
			result = result + char(it + 'a');
		}

		return result;
	}
};
