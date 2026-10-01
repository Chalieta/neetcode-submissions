class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for (auto i : intervals) {
            int start = i[0];
            int end = i[1];
            int lastEnd = result.back()[1];
            if (start <= lastEnd) {
                result.back()[1] = max(end, lastEnd);
            } else {
                result.push_back({start, end});
            }
        }

        return result;
    }
};
