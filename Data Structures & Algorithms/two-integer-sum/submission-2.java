class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; ++i) {
            if (mp.containsKey(nums[i])) {
                return new int[] {mp.get(nums[i]), i};
            }
            int diff = target - nums[i];
            mp.put(diff, i);
        }

        return new int[] {};
    }
}
