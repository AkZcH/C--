class Solution {
public:
    int firstOccur(vector<int>& nums, int target, int low, int high){
        if(high<low){
            return -1;
        }

        int mid = low + (high-low)/2;

        if(((mid !=0 && nums[mid-1] != target) || mid==0) && nums[mid]==target){
            return mid;
        }

        if(nums[mid]< target){
            return firstOccur(nums, target, mid+1, high);
        }

        else{
            return firstOccur(nums, target, low, mid-1);
        }
    }

    int lastOccur(vector<int>& nums, int target, int low, int high){
        if(high<low){
            return -1;
        }

        int mid = low + (high-low)/2;
        int n = nums.size();
        if(((mid != n-1 && nums[mid+1] != target) || mid==n-1) && nums[mid]==target){
            return mid;
        }

        if(nums[mid]> target){
            return lastOccur(nums, target, low, mid-1);
        }

        else{
            return lastOccur(nums, target, mid+1, high);
        }
    }


    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int first = firstOccur(nums, target, 0, n-1);
        int last = lastOccur(nums, target, 0, n-1);

        ans.push_back(first);
        ans.push_back(last);

        return ans;
    }
};
