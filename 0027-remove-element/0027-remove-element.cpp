class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>ans;

        for(int x:nums)
            if(x!=val)
                ans.push_back(x);
            
            for(int i=0;i<ans.size();i++)
                nums[i]=ans[i];
            
            return ans.size();
        
    }
};