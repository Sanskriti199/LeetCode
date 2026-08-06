#include <vector>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        int n = citations.size();
        std::vector<int> count(n + 1, 0);

        for (int c : citations) {
            if (c >= n) {
                count[n]++;
            } else {
                count[c]++;
            }
        }

        int total_papers = 0;
        for (int h = n; h >= 0; --h) {
            total_papers += count[h];
            if (total_papers >= h) {
                return h;
            }
        }

        return 0;
    }
};