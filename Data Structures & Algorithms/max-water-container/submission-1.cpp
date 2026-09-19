class Solution {
public:
    int maxArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }

        int L = 0, R = heights.size() - 1;
        int res = 0;

        while (L < R) {
            int width = R - L;
            int height = min(heights[L], heights[R]);
            int area = width * height;
            res = max(res, area);

            if (heights[L] <= heights[R]) {
                L++;
            } else {
                R--;
            }
        }

        return res;
    }
};
