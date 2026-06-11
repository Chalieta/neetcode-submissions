class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int distance = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                auto [r, c] = q.front();
                q.pop();
                int neighbors[4][2] = {{r - 1, c}, {r + 1, c}, {r, c - 1}, {r, c + 1}};
                for (auto neighbor : neighbors) {
                    int newR = neighbor[0];
                    int newC = neighbor[1];
                    if (newR < 0 || newR >= ROWS || newC < 0 || newC >= COLS || grid[newR][newC] != 2147483647) {
                        continue;
                    }
                    grid[newR][newC] = distance + 1;
                    q.push({newR, newC});
                }
            }
            distance++;
        }

        return;
    }
};
