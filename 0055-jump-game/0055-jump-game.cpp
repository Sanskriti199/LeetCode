class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reachable = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (i > max_reachable) {
                return false;
            }
            max_reachable = max(max_reachable, i + nums[i]);
            if (max_reachable >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};