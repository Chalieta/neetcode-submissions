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
            result.push_back(combination);
            return;
        }

        combination.push_back(nums[index]);
        dfs(nums, index, target-nums[index], combination); // Exhausts the current integer
        combination.pop_back(); // The first dfs() returns which indicates we have exhausted the current integer of all its potentials
        dfs(nums, index+1, target, combination); // Move to the next integer
    }
};
