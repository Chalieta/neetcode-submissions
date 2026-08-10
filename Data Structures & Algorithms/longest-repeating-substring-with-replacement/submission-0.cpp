class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;
        unordered_set<char> charSet(s.begin(), s.end());

        for (char c : charSet) {
            int count = 0, L = 0;
            for (int R = 0; R < s.length(); ++R) {
                if (s[R] == c) {
                    count++;
                }

                while ((R - L + 1) - count > k) {
                    if (s[L] == c) {
                        count--;
                    }
                    L++;
                }

                maxLength = max(maxLength, R - L + 1);
            }
        }

        return maxLength;
    }
};
