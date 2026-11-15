int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];

    // dp[j] = number of paths to reach column j in the current row
    int* dp = (int*)calloc(n, sizeof(int));

    dp[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[j] = 0;
            } else if (j > 0) {
                dp[j] += dp[j - 1];
            }
        }
    }

    int result = dp[n - 1];
    free(dp);
    return result;
}