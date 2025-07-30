int Bsearch(int* nums, int numsSize, int target, int low, int high) {
    if(low>high){
        return -1;
    }

    int mid = low + (high - low)/2;

    if(nums[mid]==target){
        return mid;
    }

    else if(nums[mid]<target){
        return Bsearch(nums, numsSize, target, mid+1, high);
    }

    else{
        return Bsearch(nums, numsSize, target, low, mid-1);
    }
}

int search(int *nums, int numsSize, int target){
    return Bsearch(nums, numsSize, target, 0, numsSize-1);
}
