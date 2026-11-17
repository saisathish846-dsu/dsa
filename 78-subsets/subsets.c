#include <stdlib.h>

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1 << numsSize;                      // 2^n subsets
    int** result = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    *returnSize = total;

    for (int mask = 0; mask < total; mask++) {
        int count = __builtin_popcount(mask);       // number of set bits = subset size
        (*returnColumnSizes)[mask] = count;
        result[mask] = (int*)malloc((count > 0 ? count : 1) * sizeof(int));

        int idx = 0;
        for (int j = 0; j < numsSize; j++) {
            if (mask & (1 << j)) {
                result[mask][idx++] = nums[j];
            }
        }
    }
    return result;
}