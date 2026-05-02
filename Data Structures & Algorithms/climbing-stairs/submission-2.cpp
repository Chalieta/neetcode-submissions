class Solution {
public:
    unordered_map<int, int> mp;

    int climbStairs(int n) {
        if (n < 0) {
            return 0;
        }

        if (n == 0) {
            return 1;
        }

        if (mp.find(n) != mp.end()) {
            return mp[n];
        } else {
            mp[n] = climbStairs(n-1) + climbStairs(n-2);
        }

        return mp[n];
    }
};
