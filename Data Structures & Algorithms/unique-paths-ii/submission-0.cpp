class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROWS = obstacleGrid.size();
        int COLS = obstacleGrid[0].size();
        vector<vector<int>> cache(ROWS, vector<int>(COLS, -1));

        return dfs(0, 0, ROWS, COLS, cache, obstacleGrid);
    }

    int dfs(int r, int c, int ROWS, int COLS, vector<vector<int>>& cache, vector<vector<int>>& obstacleGrid) {
        if (r >= ROWS || c >= COLS || obstacleGrid[r][c] == 1) {
            return 0;
        }

        if (r == ROWS - 1 && c == COLS - 1) {
            return 1;
        }

        if (cache[r][c] != -1) {
            return cache[r][c];
        }

        cache[r][c] = dfs(r + 1, c, ROWS, COLS, cache, obstacleGrid) + dfs(r, c + 1, ROWS, COLS, cache, obstacleGrid);
        return cache[r][c];
    }
};