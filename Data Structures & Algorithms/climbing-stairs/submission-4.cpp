class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        vector<int> dp = {1, 2};
        int i = 3;
        while (i <= n) {
            int tmp = dp[1];
            dp[1] = dp[0] + tmp;
            dp[0] = tmp;
            ++i;
        }

        return dp[1];
    }
};
