class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        unordered_set<int> charSet;

        int L = 0;
        for (int R = 0; R < s.length(); ++R) {
            while(charSet.find(s[R]) != charSet.end()) {
                charSet.erase(s[L]);
                L++;
            }
            charSet.insert(s[R]);
            maxLength = max(maxLength, R - L + 1);
        }

        return maxLength;
    }
};
