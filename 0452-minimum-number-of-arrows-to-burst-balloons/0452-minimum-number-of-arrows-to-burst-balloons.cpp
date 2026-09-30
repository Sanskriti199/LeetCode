class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int arrows = 0;
        long long lastArrow = LLONG_MIN;

        for (auto& balloon : points) {
            int start = balloon[0];
            int end = balloon[1];

            if (start > lastArrow) {
                arrows++;
                lastArrow = end;
            }
        }

        return arrows;
    }
};