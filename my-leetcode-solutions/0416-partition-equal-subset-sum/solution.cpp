class Solution {
public:

    bool f(int index, int target, vector<int> &nums){
        int n = nums.size();
        vector<bool> prev(target + 1, 0);
        vector<bool> curr(target + 1, 0);

        prev[0] = curr[0] = true;
        if(nums[0]<=target) prev[nums[0]] = 0;

        for(int i=1; i<n; i++){
            for(int j = 1; j<=target; j++){
                bool notTake = prev[j];
                bool take = false;

                if(j>=nums[i]){
                take = prev[j - nums[i]];
                }

                curr[j] = take | notTake;
            }
            prev = curr;
        }

       
        return prev[target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        if(sum%2==1) return false;

        else{
            return f(n-1, sum/2, nums);
        }
    }
};
