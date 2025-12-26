class Solution {
public:
    int f(vector<int>& arr, int target){
        int n = arr.size();
        vector<int> prev(target+1, 0) , curr(target+1, 0);
        if(arr[0]==0) prev[0] = 2;
        else prev[0] = 1;

        if(arr[0] != 0 && arr[0]<=target) prev[arr[0]] = 1;

        for(int i=1; i<n; i++){
            fill(curr.begin(), curr.end(), 0);
            for(int j=0; j<=target; j++){
                int notTake = prev[j];

                int Take = 0;
                if(arr[i]<=j) Take = prev[j - arr[i]];

                curr[j] = notTake + Take;
            }
            prev = curr;
        } 

        return prev[target];
    }

    int countPartitions(int n, int target, vector<int> &num){
        int sum = 0;
        for(int i = 0; i<n; i++) sum += num[i];
        if((sum < abs(target)) || (sum - target)%2 != 0) return 0;
        return f(num, (sum - target)/2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, target, nums);
    }
};
