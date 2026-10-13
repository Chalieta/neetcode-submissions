class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMin = 1, curMax = 1;

        for (int num : nums) {
            int tmp = curMax * num;
            curMax = max(max(curMax * num, curMin * num), num); // Find the max among the products of num with curMax, curMin, and num by itself
            curMin = min(min(tmp, curMin * num), num); // We track curMin, because big negative number can turn into a big positive number when multiplied with a negative number
            res = max(res, curMax);
        }
        
        return res;
    }
};
