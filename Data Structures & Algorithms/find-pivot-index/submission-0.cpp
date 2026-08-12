class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix;
        int sum = 0;
        for (int num : nums) {
            sum += num;
            prefix.push_back(sum);
        }

        for (int i = 0; i < n; ++i) {
            int leftSum = i ? prefix[i - 1] : 0;
            int rightSum = prefix[n - 1] - prefix[i];
            if (leftSum == rightSum) {
                return i;
            }
        }

        return -1;
    }
};