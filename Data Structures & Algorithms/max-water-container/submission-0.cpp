class Solution {
public:
    int maxArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }

        int L = 0, R = heights.size() - 1;
        int maxArea = 0;

        while (L < R) {
            int width = R - L;
            int height = min(heights[R], heights[L]);
            maxArea = max(maxArea, width * height);

            if (heights[L] <= heights[R]) {
                L++;
            } else {
                R--;
            }
        }

        return maxArea;
    }
};
