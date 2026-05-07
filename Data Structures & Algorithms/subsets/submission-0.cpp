class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            int levelSize = result.size();
            for (int j = 0; j < levelSize; ++j) {
                vector<int> sub = result[j];
                sub.push_back(val);
                result.push_back(sub);
            }
        }

        return result;
    }
};
