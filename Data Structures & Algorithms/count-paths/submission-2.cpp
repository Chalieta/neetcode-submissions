class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> previousRow(n, 1);
        for (int i = m - 2; i >= 0; --i) {
            vector<int> currentRow(n, -1);
            currentRow[n - 1] = 1;
            for (int j = n - 2; j >= 0; --j) {
                currentRow[j] = previousRow[j] + currentRow[j + 1];
            }
            previousRow = currentRow;
        }
        return previousRow[0];
    }

};
