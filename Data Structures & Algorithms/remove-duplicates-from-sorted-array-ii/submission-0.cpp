class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }

        int L = 2, R = 2;

        while (R < nums.size()) {
            if (nums[R] != nums[L-2]) {
                nums[L] = nums[R];
                L++;
            }
            R++;
        }

        return L;
    }
};