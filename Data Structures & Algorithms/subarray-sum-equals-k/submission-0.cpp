class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix; // prefix[prefixSum] = frequency
        int sum = 0;
        int res = 0;
        prefix[0] = 1;
        for (int num : nums) {
            sum += num;
            int diff = sum - k;
            if (prefix.find(diff) != prefix.end()) {
                res += prefix[diff];
            }
            prefix[sum]++;
        }

        return res;
    }
};