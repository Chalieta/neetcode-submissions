class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROWS = obstacleGrid.size();
        int COLS = obstacleGrid[0].size();
        
        vector<int> previousRow(COLS, 0);
        for (int i = ROWS - 1; i >= 0; --i) {
            vector<int> currentRow(COLS, 0);
            if (i == ROWS - 1) { // Last row
                currentRow[COLS - 1] = obstacleGrid[i][COLS - 1] ? 0 : 1; // Right bottom cell
            } else { // Non-last row, last column
                currentRow[COLS - 1] = obstacleGrid[i][COLS - 1] ? 0 : previousRow[COLS - 1];
            }
            // Non-edge cells
            for (int j = COLS - 2; j >= 0; --j) {
                currentRow[j] = obstacleGrid[i][j] ? 0 : previousRow[j] + currentRow[j + 1];
            }
            previousRow = currentRow;
        }

        return previousRow[0];
    }
};