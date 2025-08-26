class Solution {
public:

    int binarySearch(vector<int>& nums, int target, int low, int high){
        if(low>high){
            return -1;
        }
        int mid = low + (high - low)/2;

        if(nums[mid]==target){
            return mid;
        }

        else if(nums[low]<=nums[mid]){
            if(target>=nums[low] && target<nums[mid]){
                return binarySearch(nums, target, low, mid-1);
            }
            else{
                return binarySearch(nums, target, mid+1, high);
            }
        }



        else{
           if(target>nums[mid] && target<=nums[high]){
                return binarySearch(nums, target, mid+1, high);

            }
            else{
                return binarySearch(nums, target, low, mid-1);
            }
        }
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int result = binarySearch(nums, target, 0, n-1);

        return result;

    }
};
