class NumArray {
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
            prefix.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int prefixRight = prefix[right];
        int prefixLeft = left ? prefix[left - 1] : 0;
        return prefixRight - prefixLeft;
    }

private:
    vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */