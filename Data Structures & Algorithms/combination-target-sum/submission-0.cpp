class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> combination;
        dfs(nums, 0, target, combination);
        return result;
    }

    void dfs(vector<int>& nums, int index, int target, vector<int>& combination) {
        if (index >= nums.size() || target < 0) {
            return;
        }

        if (target == 0) {
            return result.push_back(combination);
        }

        combination.push_back(nums[index]);
        dfs(nums, index, target-nums[index], combination);
        combination.pop_back();
        dfs(nums, index+1, target, combination);
    }
};
