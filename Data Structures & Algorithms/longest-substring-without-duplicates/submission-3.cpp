class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int L = 0;
        unordered_set<char> exist;
        for (int R = 0; R < s.length(); ++R) {
            while (exist.find(s[R]) != exist.end()) {
                exist.erase(s[L]);
                L++;
            }
            exist.insert(s[R]);
            maxLength = max(R - L + 1, maxLength);
        }

        return maxLength;
    }
};
