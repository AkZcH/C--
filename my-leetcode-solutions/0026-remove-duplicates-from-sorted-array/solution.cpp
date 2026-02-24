class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int element = nums[0];
        int index = 1;
        for(int i=1; i<n;i++){
            if(nums[i] != element){
                nums[index++] = nums[i];
                element = nums[i];
            }
        }
        return index;
    }
};
