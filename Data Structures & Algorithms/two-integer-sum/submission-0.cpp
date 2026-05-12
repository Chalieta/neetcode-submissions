class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // <difference, index of first element> as <key, value>
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.count(nums[i])) {
                result.push_back(mp[nums[i]]);
                result.push_back(i);
                break;
            } else {
                mp[target-nums[i]] = i;
            }
        }
        return result;
    }
};
