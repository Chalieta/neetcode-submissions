class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ROWS = text1.size();
        int COLS = text2.size();
        vector<int> previousRow(COLS + 1, 0);

        for (int i = ROWS - 1; i >= 0 ; --i) {
            vector<int> currentRow(COLS + 1, 0);
            for (int j = COLS - 1; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    currentRow[j] = 1 + previousRow[j + 1];
                } else {
                    currentRow[j] = max(previousRow[j], currentRow[j + 1]);
                }
            }
            previousRow = currentRow;
        }

        return previousRow[0];
    }
};
