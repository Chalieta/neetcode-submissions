class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Rows
        for (int row = 0; row < 9; ++row) {
            unordered_set<int> exist;
            for (int i = 0; i < 9; ++i) {
                if (board[row][i] == '.') {
                    continue;
                }
                if (exist.count(board[row][i])) {
                    return false;
                }
                exist.insert(board[row][i]);
            }
        }

        // Cols
        for (int col = 0; col < 9; ++col) {
            unordered_set<int> exist;
            for (int i = 0; i < 9; ++i) {
                if (board[i][col] == '.') {
                    continue;
                }
                if (exist.count(board[i][col])) {
                    return false;
                }
                exist.insert(board[i][col]);
            }
        }

        // Square
        for (int square = 0; square < 9; ++square) {
            unordered_set<int> exist;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.') {
                        continue;
                    }
                    if (exist.count(board[row][col])) {
                        return false;
                    }
                    exist.insert(board[row][col]);
                }
            }
        }

        return true;
    }
};
