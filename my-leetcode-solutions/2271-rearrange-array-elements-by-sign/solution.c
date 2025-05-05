/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    int *positives;
    int *negetives;
    int *result;
    int pcount=0;
    int ncount=0;

    result=(int*)malloc(numsSize * sizeof(int));
    positives=(int*)malloc((numsSize/2)*sizeof(int));
    negetives=(int*)malloc((numsSize/2)*sizeof(int));

    for(int i=0;i<=numsSize-1;i++){
        if(nums[i]<0){
            negetives[ncount++]=nums[i];
        }

        else if(nums[i]>=0){
            positives[pcount++]=nums[i];
        }
    }

    int index=0;
    int p=0;
    int n=0;
    while(index<numsSize){
        result[index++]=positives[p++];
        result[index++]=negetives[n++];
    }

    *returnSize = numsSize;
    free(positives);
    free(negetives);
    return result;

}
