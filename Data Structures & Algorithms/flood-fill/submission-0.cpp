class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if (initialColor == color) {
            return image;
        }
        vector<vector<int>> modImage(image);
        dfs(modImage, sr, sc, color, initialColor);
        return modImage;
    }

    void dfs(vector<vector<int>>& image, int r, int c, int color, int initialColor) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != initialColor) {
            return;
        }
        image[r][c] = color;
        dfs(image, r+1, c, color, initialColor);
        dfs(image, r-1, c, color, initialColor);
        dfs(image, r, c+1, color, initialColor);
        dfs(image, r, c-1, color, initialColor);
        return;
    }
};