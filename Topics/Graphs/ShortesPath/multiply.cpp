#include<iostream>
#include<vector>
#include<priority_queue>
using namespace std;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end) return 0;
        // code here
        int n = arr.size();
        
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
            >pq;
            
        vector<int> stepsTook(100000, 1e9);
        stepsTook[start] = 0;
        pq.push({0, start});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            int steps = 0;

            
            for(int i=0; i<n; i++){
                int result = (node * arr[i])%100000;
                if(result == end) return 1 + cost;
                
                if(1 + cost < stepsTook[result]){
                    stepsTook[result] = 1 + cost;
                    pq.push({stepsTook[result], result});
                }
            }
        }
        
        return -1;
    }
};
