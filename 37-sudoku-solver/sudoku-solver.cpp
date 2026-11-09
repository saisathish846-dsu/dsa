class Solution {
public:
    int rows[9] = {0}, cols[9] = {0}, boxes[9] = {0};

    bool solve(vector<vector<char>>& board, int pos) {
        if (pos == 81) return true;

        int i = pos / 9, j = pos % 9;
        if (board[i][j] != '.') return solve(board, pos + 1);

        int b = (i / 3) * 3 + (j / 3);
        int used = rows[i] | cols[j] | boxes[b];

        for (int d = 0; d < 9; d++) {
            int bit = 1 << d;
            if (used & bit) continue;

            board[i][j] = '1' + d;
            rows[i] |= bit;
            cols[j] |= bit;
            boxes[b] |= bit;

            if (solve(board, pos + 1)) return true;

            board[i][j] = '.';
            rows[i] &= ~bit;
            cols[j] &= ~bit;
            boxes[b] &= ~bit;
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int bit = 1 << (board[i][j] - '1');
                    rows[i] |= bit;
                    cols[j] |= bit;
                    boxes[(i / 3) * 3 + (j / 3)] |= bit;
                }
            }
        }
        solve(board, 0);
    }
};