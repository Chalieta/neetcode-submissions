class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> frequency;
        priority_queue<pair<int, int>> maxHeap;

        for (auto n : nums) {
            frequency[n]++;
        }

        for (auto& f : frequency) {
            maxHeap.push({f.second, f.first});
        }

        for (int i = 0; i < k; ++i) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};
