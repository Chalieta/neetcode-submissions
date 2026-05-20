class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp{nums[0], max(nums[0], nums[1])};

        for (int i = 2; i < nums.size(); ++i) {
            int tmp = dp[1];
            dp[1] = max(dp[1], nums[i] + dp[0]);
            dp[0] = tmp;
        }

        return dp[1];
    }
};
