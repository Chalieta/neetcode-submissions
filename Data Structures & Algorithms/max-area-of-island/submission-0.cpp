class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    int val = dfs(grid, i, j);
                    if (val > max) {
                        max = val;
                    }
                }
            }
        }
        return max;
    }

    int dfs(vector<vector<int>>& grid, int r, int c){
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || !grid[r][c]) {
            return 0;
        }

        grid[r][c] = 0;
        
        int count = 1;
        count += dfs(grid, r+1, c);
        count += dfs(grid, r-1, c);
        count += dfs(grid, r, c+1);
        count += dfs(grid, r, c-1);

        return count;
    }
};
