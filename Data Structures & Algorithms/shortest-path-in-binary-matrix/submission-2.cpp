class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();    

        if (grid[0][0]) {
            return -1;
        }

        int length = 1;
        queue<pair<int, int>> q;
        q.push(pair<int, int>{0, 0});
        while (q.size()) {
            int queueSize = q.size();
            for (int i = 0; i < queueSize; ++i) {
                pair<int, int> node = q.front();
                int r = node.first;
                int c = node.second;
                q.pop();

                // Destination reached
                if (r == ROWS - 1 && c == COLS - 1) {
                    return length;
                }

                if (!grid[r][c]) { // If node is valid (0)
                    grid[r][c] = 1;
                }

                int neighbors[8][2] = {{r+1, c}, {r-1, c}, {r, c+1}, {r, c-1}, {r+1, c+1}, {r+1, c-1}, {r-1, c+1}, {r-1, c-1}};
                for (auto neighbor : neighbors) {
                    int newR = neighbor[0];
                    int newC = neighbor[1];
                    if (newR < 0 || newR >= ROWS || newC < 0 || newC >= COLS || grid[newR][newC]) {
                        continue;
                    }
                    q.push(pair<int, int>{newR, newC});
                }
            }
            length++;
        }

        return -1;
    }
};