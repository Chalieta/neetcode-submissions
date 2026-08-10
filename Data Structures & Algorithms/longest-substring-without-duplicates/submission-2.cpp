class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int L = 0;
        unordered_map<char, int> mp;
        for (int R = 0; R < s.length(); ++R) {
            if (mp.find(s[R]) != mp.end()) {
                while (L < mp[s[R]] + 1) {
                    mp.erase(s[L]);
                    L++;
                }
            }
            mp[s[R]] = R;
            maxLength = max(R - L + 1, maxLength);
        }

        return maxLength;
    }
};
