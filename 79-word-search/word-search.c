#include <stdbool.h>
#include <string.h>

static int m, n;
static int wlen;

static bool dfs(char **board, const char *word, int r, int c, int k) {
    if (k == wlen)
        return true;
    if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] != word[k])
        return false;

    char tmp = board[r][c];
    board[r][c] = '#';                 // mark visited

    bool found = dfs(board, word, r + 1, c, k + 1) ||
                 dfs(board, word, r - 1, c, k + 1) ||
                 dfs(board, word, r, c + 1, k + 1) ||
                 dfs(board, word, r, c - 1, k + 1);

    board[r][c] = tmp;                 // backtrack
    return found;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word) {
    m = boardSize;
    n = boardColSize[0];
    wlen = strlen(word);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(board, word, i, j, 0))
                return true;
        }
    }
    return false;
}