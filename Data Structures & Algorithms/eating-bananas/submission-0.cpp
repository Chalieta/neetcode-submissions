class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1; // Minimum speed
        int r = *max_element(piles.begin(), piles.end()); // Maximum speed
        int mid; // Speed iterator
        long totalTime;
        int minSpeed = r;

        while (l <= r) {
            mid = (l + r)/2;
            totalTime = 0;
            for (int i = 0; i < piles.size(); ++i) {
                totalTime += ceil(static_cast<double>(piles[i])/mid);
            }

            // If total time takes longer than h, increase the speed
            if (totalTime > h) {
                l = mid + 1;
            } else {
                minSpeed = mid; // Record the speed
                // Lower the speed to see if it's even lower than the current minimum
                r = mid - 1;
            }

        }

        return minSpeed;
    }
};
