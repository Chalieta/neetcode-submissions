class Solution {
public:
    unordered_map<int, int> mp;
    int rob(vector<int>& nums) {
        return dfs(nums, 0);
    }

    int dfs(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }

        if (mp.find(i) != mp.end()) {
            return mp[i];
        }

        mp[i] = max(dfs(nums, i + 1), nums[i] + dfs(nums, i + 2));
        return mp[i];
    }
};
