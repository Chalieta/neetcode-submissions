class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                break; // Because nums is sorted, we expect the first element to be <= 0
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Deduplication logic to avoid duplicate sublist
            }
            int L = i + 1, R = nums.size() - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    res.push_back({nums[i], nums[L], nums[R]});
                    L++;
                    R--;
                    while (L < R && nums[L] == nums[L - 1]) {
                        L++; // Deduplication logic to avoid duplicate sublist
                    } 
                } else if (sum < 0) {
                    L++;
                } else {
                    R--;
                }
            }
        }

        return res;
    }
};
