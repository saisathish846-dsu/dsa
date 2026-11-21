#include <stdlib.h>
#include <string.h>

static int cmp(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

static void backtrack(int *nums, int n, int start,
                      int *path, int len,
                      int **res, int *sizes, int *count) {
    // record current subset
    res[*count] = (int *)malloc((len ? len : 1) * sizeof(int));
    memcpy(res[*count], path, len * sizeof(int));
    sizes[*count] = len;
    (*count)++;

    for (int i = start; i < n; i++) {
        if (i > start && nums[i] == nums[i - 1]) continue;  // skip duplicates at same level
        path[len] = nums[i];
        backtrack(nums, n, i + 1, path, len + 1, res, sizes, count);
    }
}

int **subsetsWithDup(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int cap = 1 << numsSize;  // upper bound on number of subsets
    int **res = (int **)malloc(cap * sizeof(int *));
    int *sizes = (int *)malloc(cap * sizeof(int));
    int *path = (int *)malloc((numsSize ? numsSize : 1) * sizeof(int));
    int count = 0;

    backtrack(nums, numsSize, 0, path, 0, res, sizes, &count);

    free(path);
    *returnSize = count;
    *returnColumnSizes = sizes;
    return res;
}