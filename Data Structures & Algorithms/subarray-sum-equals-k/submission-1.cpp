class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int curSum = 0;
        unordered_map<int, int> prefixSums;

        prefixSums[0] = 1;

        for (int n : nums) {
            curSum += n;
            int diff = curSum - k;
            if (prefixSums.find(diff) != prefixSums.end()) {
                res += prefixSums[diff];
            }
            prefixSums[curSum]++;
        }

        return res;
    }
};