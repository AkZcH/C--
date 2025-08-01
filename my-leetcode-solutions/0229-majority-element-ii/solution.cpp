class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1=0;
        int count2=0;
        int el1= INT_MIN;
        int el2= INT_MIN;
        vector<int> ls;

        for(int i=0; i<n; i++){
            if(count1==0 && nums[i]!=el2){
                count1=1;
                el1=nums[i];
            }

            else if(count2==0 && nums[i]!=el1){
                count2=1;
                el2=nums[i];
            }

            else if(nums[i]==el1){
                count1++;
            }

            else if(nums[i]==el2){
                count2++;
            }

            else{
                count1--;
                count2--;
            }
        }

          int minimum=int(n/3) + 1;
            count1=0;
            count2=0;
            for(int num : nums){
                if(num==el1){
                    count1++;
                }
                else if(num==el2){
                    count2++;
                }
            }

             if(count1>=minimum){
                ls.push_back(el1);
            }
                if(count2>=minimum){
                ls.push_back(el2);
                }
                

        return ls;

    }
};
