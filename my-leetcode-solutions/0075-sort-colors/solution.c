void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void sortColors(int* nums, int numsSize) {
    int c0=0, c1=0, c2=0;

    for(int i=0; i<=numsSize-1;i++){
        if(nums[i]==0){
            swap(&nums[i], &nums[c0]);
            c0++;
        }
    }
    c1=c0;

    for(int i=0; i<=numsSize-1;i++){
        if(nums[i]==1){
            swap(&nums[i], &nums[c1]);
            c1++;
        }
    }
}
