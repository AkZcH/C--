int simpleRob(int* nums, int start, int end){
    int p1=0;
    int p2=0;
    int current;

    for(int i=start;i<end;i++){
        current = (p2 > (p1 + nums[i])) ? p2 : (p1 + nums[i]);
        p1=p2;
        p2=current;
    }

    return p2;
}

int rob(int* nums, int numsSize) {
    if(numsSize==0){
        return 0;
    }

    if(numsSize==1){
        return nums[0];
    }

    int max1= simpleRob(nums, 0, numsSize-1);
    int max2= simpleRob(nums, 1, numsSize);

    int max = (max2 > max1) ? max2:max1;

    return max;

    
}
