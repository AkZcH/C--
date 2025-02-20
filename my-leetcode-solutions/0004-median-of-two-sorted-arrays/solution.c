double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int *arr = (int*)malloc(totalSize * sizeof(int));

    int i=0,j=0,k=0;

    while(i<nums1Size && j<nums2Size){
        if(nums1[i]<nums2[j]){
            arr[k++]=nums1[i++];
        }
        else{
             arr[k++]=nums2[j++];
        }
    }

    while(i<nums1Size){
        arr[k++]=nums1[i++];
    }

    while(j<nums2Size){
        arr[k++]=nums2[j++];
    }

double median;
if((totalSize%2)!=0){
    median=arr[(totalSize-1)/2];
}
else{
    median= (arr[totalSize/2 - 1] + arr[totalSize/2])/2.0;
}

free(arr);
return median;
}
