class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0);
        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
        }
        
        int color = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (freq[color] == 0) {
                color++;
            }
            nums[i] = color;
            freq[color]--;
        }
    }
};