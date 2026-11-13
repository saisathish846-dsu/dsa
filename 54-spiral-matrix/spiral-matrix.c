int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize, n = matrixColSize[0];
    int *res = malloc(m * n * sizeof(int));
    int k = 0;
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) res[k++] = matrix[top][j];
        top++;
        for (int i = top; i <= bottom; i++) res[k++] = matrix[i][right];
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) res[k++] = matrix[bottom][j];
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) res[k++] = matrix[i][left];
            left++;
        }
    }

    *returnSize = k;
    return res;
}