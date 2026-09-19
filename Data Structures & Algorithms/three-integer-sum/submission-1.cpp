class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> count;
        vector<vector<int>> res;

        for (int num : nums) {
            count[num]++;
        }

        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]]--;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Deduplication logic to avoid duplicate sublist
            }
            for (int j = i + 1; j < nums.size(); ++j) {
                count[nums[j]]--;
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue; // Deduplicaiton logic to avoid duplicate sublist
                }
                int target = -(nums[i] + nums[j]);
                if (count[target] > 0) {
                    res.push_back({nums[i], nums[j], target});
                }
            }

            for (int j = i + 1; j < nums.size(); ++j) {
                count[nums[j]]++; // Restore j counts for next i iteration
            }
        }
        return res;
    }
};
