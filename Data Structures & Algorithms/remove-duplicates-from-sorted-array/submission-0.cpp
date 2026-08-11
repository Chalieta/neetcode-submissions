class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int L = 0;
        int res = 1;
        for (int R = 1; R < nums.size(); ++R) {
            if (nums[L] != nums[R]) {
                L++;
                nums[L] = nums[R];
                res++;
            }
        }
        return res;
    }
};