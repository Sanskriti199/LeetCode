class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int current_sum=0;
        int minimum_length=INT_MAX;
        int a=nums.size();

        for(int right=0;right<a;right++){
            current_sum += nums[right];

            while(current_sum>=target){
                minimum_length=min(minimum_length,right-left+1);
                current_sum-=nums[left];
                left++;
            }
        }
        return(minimum_length==INT_MAX)?0:minimum_length;
    }
};