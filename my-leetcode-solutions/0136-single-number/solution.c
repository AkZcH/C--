
int singleNumber(int* nums, int numsSize) {
    int unique=0;
    
    for(int i=0; i<=numsSize-1;i++){
        unique ^=nums[i];
    }

    return unique;
}
