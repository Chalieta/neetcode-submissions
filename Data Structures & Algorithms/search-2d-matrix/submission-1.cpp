class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() - 1;
        int midY;

        while (low <= high) {
            midY = (low + high)/2;
            if (matrix[midY][0] > target) {
                high = midY - 1;
            } else if (matrix[midY][0] < target) {
                low = midY + 1;
            } else {
                return true;
            }
        }

        if (high < 0) {
            return false;
        }

        auto sub = matrix[high];
        int left = 0;
        int right = sub.size() - 1;
        int midX;

        while (left <= right) {
            midX = (left + right)/2;
            if (sub[midX] > target) {
                right = midX - 1;
            } else if (sub[midX] < target) {
                left = midX + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
