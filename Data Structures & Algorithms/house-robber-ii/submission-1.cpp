class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        // Consider the first house and exclude the last house
        vector<int> dp1{nums[0], max(nums[0], nums[1])};
        for (int i = 2; i < nums.size() - 1; ++i) {
            int tmp = dp1[1];
            dp1[1] = max(dp1[1], nums[i] + dp1[0]);
            dp1[0] = tmp;
        }

        // Consider the last house and exclude the first house
        vector<int> dp2{nums[1], max(nums[1], nums[2])};
        for (int i = 3; i < nums.size(); ++i) {
            int tmp = dp2[1];
            dp2[1] = max(dp2[1], nums[i] + dp2[0]);
            dp2[0] = tmp;
        }

        return max(dp1[1], dp2[1]);
    }
};
