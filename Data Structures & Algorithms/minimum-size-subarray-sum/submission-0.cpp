class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0;
        int sum = 0;
        int minLength = INT_MAX;

        for(int R = 0; R < nums.size(); ++R) {
            sum += nums[R];
            while (sum >= target) {
                minLength = min(minLength, R - L + 1);
                sum -= nums[L];
                L++;
            }
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};