class Solution {
public:
    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                swap(&nums[i], &nums[index]);
                index++;
            }
        }
        int index1=0;
        for(int i=0; i<index; i++){
            if(nums[i] == 2){
                swap(&nums[i], &nums[index1]);
                index1++;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
