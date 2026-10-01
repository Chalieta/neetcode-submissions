class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        unordered_set<int> seen;

        int L = 0;
        for (int R = 0; R < s.length(); ++R) {
            while (seen.find(s[R]) != seen.end()) {
                seen.erase(s[L]);
                L++;
            }
            seen.insert(s[R]);
            maxLength = max(maxLength, R - L + 1);
        }

        return maxLength;
    }
};
