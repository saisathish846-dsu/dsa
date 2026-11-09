class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int bit = 1 << (board[i][j] - '1');
                int b = (i / 3) * 3 + (j / 3);

                if ((rows[i] & bit) || (cols[j] & bit) || (boxes[b] & bit)) {
                    return false;
                }

                rows[i] |= bit;
                cols[j] |= bit;
                boxes[b] |= bit;
            }
        }

        return true;
    }
};