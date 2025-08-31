class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int n = nums.size();

        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }

        int index = k-1;

        while(index > 0){
            pq.pop();
            index--;
        }

        return pq.top();
    }
};
