class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() == 0) return 0;
        int L = 0;
        int maxLength = 1;
        // Case 1
        for (int R = 0; R < (int)arr.size() - 1; ++R) {
            if ((R % 2 == 1 && arr[R] <= arr[R + 1]) || 
            (R % 2 == 0 && arr[R] >= arr[R + 1])) {
                L = R + 1;
            }
            maxLength = max(maxLength, R - L + 2);
        }

        L = 0;
        // Case 2
        for (int R = 0; R < (int)arr.size() - 1; ++R) {
            if ((R % 2 == 0 && arr[R] <= arr[R + 1]) || 
            (R % 2 == 1 && arr[R] >= arr[R + 1])) {
                L = R + 1;
            }
            maxLength = max(maxLength, R - L + 2);
        }

        return maxLength;
    }
};