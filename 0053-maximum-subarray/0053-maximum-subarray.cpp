
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int c = 0, ms = INT_MIN;

        for(int val : nums) {
            c += val;
            ms = max(c, ms);

            if(c < 0) {
                c = 0;
            }
        }

        return ms;
    }
};





