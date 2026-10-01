class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> frequency;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto n : nums) {
            frequency[n]++;
        }

        for (auto& f : frequency) {
            minHeap.push({f.second, f.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        for (int i = 0; i < k; ++i) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
