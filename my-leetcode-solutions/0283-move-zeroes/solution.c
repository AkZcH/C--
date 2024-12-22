void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;

}

    

void moveZeroes(int* nums, int numsSize) {
    int count=0;
    for(int i=0; i<numsSize; i++){
        if(nums[i]!=0){
            swap(&nums[count++], &nums[i]);
        }
    }
}
