class Solution {
public:
     bool binarySearch(vector<int>& nums, int target, int low, int high){
        if(low>high){
            return false;
        }
        int mid = low + (high - low)/2;

        if(nums[mid]==target){
            return true;
        }

        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            return binarySearch(nums, target, low+1, high-1);
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

    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        bool found =  binarySearch(nums, target, 0, n-1);
        return found;
    }
};
