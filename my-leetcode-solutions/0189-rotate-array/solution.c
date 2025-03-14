void rotate(int* nums, int numsSize, int k) {
    int *newarr;
    newarr=(int*)malloc(numsSize*(sizeof(int))); 
    for(int i=0;i<numsSize;i++){
        newarr[(i+k)%numsSize]= nums[(i)%numsSize];
    }
    
    for(int j=0;j<numsSize; j++){
        printf("%d,", newarr[j]);
    }

        for (int i = 0; i < numsSize; i++) {
        nums[i] = newarr[i];
    }

    free(newarr);
}
