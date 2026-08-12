class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int l = 0, r = height.size() - 1;
        int lMax = height[l], rMax = height[r];
        int area = 0;

        while (l < r) {
            if (lMax < rMax) {
                l++;
                lMax = max(lMax, height[l]);
                area += lMax - height[l];
            } else {
                r--;
                rMax = max(rMax, height[r]);
                area += rMax - height[r];
            }
        }

        return area;
    }
};
