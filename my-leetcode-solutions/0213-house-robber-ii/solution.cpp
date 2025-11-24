class Solution {
public:

     int help(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        vector<int> DP(n);
        DP[0]=nums[0];
        DP[1]=max(nums[0], nums[1]);

        for(int i=2; i<n; i++){
            DP[i]=max(nums[i] + DP[i-2], DP[i-1]);
        }


        return DP[n-1];
    }

    long long int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];
        
        vector<int> nums1(n-1);
        vector<int> nums2(n-1);

        for(int i=0; i<n-1; i++){
            nums1[i]=nums[i];
            nums2[i]=nums[i+1];
        }

        return max(help(nums1), help(nums2));

    }
};
