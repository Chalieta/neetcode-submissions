class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int fresh = 0;

        // Find all the rotten fruits and place them in queue
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == 1) {
                    fresh++;
                }

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int duration = 0;
        while (fresh > 0 && !q.empty()) {
            int queueSize = q.size();
            for (int i = 0; i < queueSize; ++i) {
                auto [r, c] = q.front();
                q.pop();


                // Add valid neighbors to queue
                for (pair<int, int> direction : directions) {
                    int newR = r + direction.first;
                    int newC = c + direction.second;
                    if ( newR < 0 || newR >= ROWS || newC < 0 || newC >= COLS || grid[newR][newC] != 1) {
                        continue;
                    }
                    grid[newR][newC] = 2;
                    fresh--;
                    q.push(pair<int, int>{newR, newC});
                }
            }
            duration++;
        }

        return fresh == 0 ? duration : -1;
    }
};
