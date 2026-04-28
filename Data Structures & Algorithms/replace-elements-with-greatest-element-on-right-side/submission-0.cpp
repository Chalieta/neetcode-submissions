class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max = -1;
        int hold;
        // Iterate from the back
        for (int i = arr.size()-1; i >= 0; --i) {
            if (max < 0) { // Account for the last element being -1
                // Perform a swap
                hold = arr[i];
                arr[i] = max;
                max = hold;
                continue;
            } 
            if (arr[i] > max) {
                // Perform a swap because for we want to replace the current element with
                // the max value, but the current element will be the max value for the next
                // element
                hold = arr[i];
                arr[i] = max;
                max = hold;
            } else {
                // The max value hasn't changed
                arr[i] = max;
            }
        }
        return arr;
    }
};