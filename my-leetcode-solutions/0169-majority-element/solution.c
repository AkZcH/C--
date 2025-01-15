int majorityElement(int* nums, int numsSize) {
    int candidate=0, count=0;

    for(int i=0;i<numsSize;i++){
        if(count==0){
            candidate=nums[i];
        }

        count += (candidate == nums[i]) ? 1:-1;
    }

    count = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==candidate){
            count ++;
        }
    }

    if(count>numsSize/2){
        return candidate;
    }

    else{
        return -1;
    }
}
