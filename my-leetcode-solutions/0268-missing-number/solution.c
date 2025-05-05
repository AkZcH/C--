void swap(int *a, int *b){
    int temp = *a;
    *a= *b;
    *b = temp;
}

int partition(int *arr, int low, int high){
    int pivot=arr[low];
    int i=low;
    int j=high;

    while(i<j){
        while(i<=high && arr[i]<=pivot){
            i++;
        }

        while(arr[j]>pivot && j>=low){
            j--;
        }

        if(i<j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void qs(int *arr, int low, int high){
    if(low<high){
        int pivot=partition(arr, low, high);
        qs(arr, low, pivot-1);
        qs(arr, pivot+1, high);
    }
}

int missingNumber(int* nums, int numsSize) {
    qs(nums, 0, numsSize-1);

    for(int i=0; i<numsSize-1; i++){
        if(nums[i+1]!=nums[i]+1){
            return nums[i]+1;
        }
    }

    if (nums[0] != 0) return 0; 
    return nums[numsSize - 1] + 1;
}
