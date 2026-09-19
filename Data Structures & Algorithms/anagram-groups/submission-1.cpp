class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const auto& s : strs) {
            string sortedString = s;
            sort(sortedString.begin(), sortedString.end());
            mp[sortedString].push_back(s);
        }

        vector<vector<string>> res;
        for (auto m : mp) {
            res.push_back(m.second);
        }

        return res;
    }
};
