class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> copy1(nums1.begin(), nums1.begin() + m);
        int i = 0, j = 0, k = 0;
        while (k < m + n) {
            // j >= n means nums2 has been exhausted
            if (j >= n || (i < m && copy1[i] <= nums2[j])) {
                nums1[k++] = copy1[i++];
            } else {
                nums1[k++] = nums2[j++];
            }
        }
    }
};