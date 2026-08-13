class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // O(1) Space Solution using fast and slow pointers
        // If we reimagine the nums as a linked list where each index points to 
        // the next index depending on its a value, duplicate numbers indicate that 
        // there are >1 index that points to the same value. This indicates a cycle.
        // The duplicate number is the head of the cycle.

        int slow = 0, fast = 0;

        // Find cycle
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        // Calculate the head of the cycle
        int slow2 = 0;
        while (true) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) {
                return slow;
            }
        }

    }
};
