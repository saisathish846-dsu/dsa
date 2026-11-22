int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** tri = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    *returnSize = numRows;

    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        tri[i] = (int*)malloc((i + 1) * sizeof(int));

        tri[i][0] = 1;
        tri[i][i] = 1;
        for (int j = 1; j < i; j++) {
            tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
        }
    }
    return tri;
}