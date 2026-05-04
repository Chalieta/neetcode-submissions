class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> results;
        quickSort(points, 0, points.size() - 1);
        results.assign(points.begin(), points.begin() + k);
        return results;
    }

    void quickSort(vector<vector<int>>& points, int s, int e) {
        int left = s;

        // If array's length is 1, return array
        if ((e - s + 1) <= 1) {
            return;
        }

        int pivotX = points[e][0];
        int pivotY = points[e][1];
        double pivotDist = sqrt((double)pivotX * pivotX + (double)pivotY * pivotY);

        for (int i = s; i < e; ++i) {
            int x = points[i][0];
            int y = points[i][1];
            double dist = sqrt((double)x * x + (double)y * y);

            if (dist < pivotDist) {
                auto temp = points[i];
                points[i] = points[left];
                points[left] = temp;
                left++;
            }
        }

        auto temp = points[e];
        points[e] = points[left];
        points[left] = temp;

        quickSort(points, s, left - 1);
        quickSort(points, left + 1, e);
    }
};
