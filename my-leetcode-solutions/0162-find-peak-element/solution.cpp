class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int Count=0;
        int n = nums.size();
        int low=0;
        int high=n-1;

        while(low<high){
            int mid = low + (high-low)/2;

            if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }

            else{
                high = mid;
            }
        }

        return low;
    }
};
