class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int res = 0;

        int L = 0, maxFrequency = 0;
        for (int R = 0; R < s.length(); ++R) {
            count[s[R]]++;
            maxFrequency = max(maxFrequency, count[s[R]]);

            while ((R - L + 1) - maxFrequency > k) {
                count[s[L]]--;
                L++;
            }

            res = max(res, R - L + 1);
        }

        return res;
    }
};
