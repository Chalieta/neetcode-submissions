class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int n = height.size();
        int leftMax = 0, rightMax = 0;
        int l = 0, r = n - 1;
        int res = 0;

        while (l < r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);
            if (leftMax < rightMax) {
                res += leftMax - height[l];
                l++;
            } else {
                res += rightMax - height[r];
                r--;
            }
        }

        return res;
    }
};
