char ***out; int cnt, cap, N;
int pl[20]; char cl[20], dg[40], an[40];

void bt(int r) {
    if (r == N) {
        if (cnt == cap) { cap = cap ? cap * 2 : 16; out = realloc(out, cap * sizeof(char **)); }
        char **b = malloc(N * sizeof(char *));
        for (int i = 0; i < N; i++) {
            b[i] = malloc(N + 1); memset(b[i], '.', N);
            b[i][pl[i]] = 'Q'; b[i][N] = 0;
        }
        out[cnt++] = b;
        return;
    }
    for (int c = 0; c < N; c++) {
        int d = r - c + N - 1, a = r + c;
        if (cl[c] || dg[d] || an[a]) continue;
        cl[c] = dg[d] = an[a] = 1; pl[r] = c;
        bt(r + 1);
        cl[c] = dg[d] = an[a] = 0;
    }
}

char ***solveNQueens(int n, int *returnSize, int **returnColumnSizes) {
    out = NULL; cnt = cap = 0; N = n;
    bt(0);
    *returnSize = cnt;
    *returnColumnSizes = malloc(cnt * sizeof(int));
    for (int i = 0; i < cnt; i++) (*returnColumnSizes)[i] = n;
    return out;
}