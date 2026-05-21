class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mp(m, vector<int>(n, -1));
        return bruteForce(0, 0, m, n, mp);
    }

    int bruteForce(int r, int c, int rows, int cols, vector<vector<int>>& mp) {
        if (r >= rows || c >= cols) {
            return 0;
        }

        if (r == rows - 1 && c == cols - 1) {
            return 1;
        }

        if (mp[r][c] != -1) {
            return mp[r][c];
        }

        mp[r][c] = bruteForce(r + 1, c, rows, cols, mp) + bruteForce(r, c + 1, rows, cols, mp);
        return mp[r][c];
    }
};