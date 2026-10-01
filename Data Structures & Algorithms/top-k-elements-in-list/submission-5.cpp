class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;
        for (int num : nums) {
            mp[num]++;
        }
        for (auto& pair : mp) {
            minHeap.push({pair.second, pair.first}); // The value is now first for comparing purpose
            // Whenever the size of the heap is greater than k, we remove the smallest value
            // so the remaining values are top k frequent elements
            if (minHeap.size() > k) {
                minHeap.pop();
            }    
        }
        for (int i = 0; i < k; ++i) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};
