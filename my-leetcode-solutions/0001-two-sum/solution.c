/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate space to return the indices
    int* result = (int*)malloc(2 * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) { // Ensure i != j
            if (nums[i] + nums[j] == target) {
                result[0] = i;  // Store the first index
                result[1] = j;  // Store the second index
                *returnSize = 2; // Set the return size to 2
                return result;   // Return the result
            }
        }
    }
    
    // If no solution is found, set returnSize to 0
    *returnSize = 0;
    return NULL;
}



