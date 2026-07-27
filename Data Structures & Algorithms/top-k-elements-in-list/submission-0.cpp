class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> maxHeap;
        for (int num : nums) {
            mp[num]++;
        }
        for (auto& pair : mp) {
            maxHeap.push({pair.second, pair.first}); // The value is used as comparator
        }
        int i = 0;
        while (i < k) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
            i++;
        }
        return res;
    }
};
