class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        for (char c : s) {
            if (s_map.count(c)) {
                s_map[c]++;
            } else {
                s_map[c] = 1;
            }
        }
        for (char c : t) {
            if (t_map.count(c)) {
                t_map[c]++;
            } else {
                t_map[c] = 1;
            }
        }
        return s_map == t_map;
    }
};
