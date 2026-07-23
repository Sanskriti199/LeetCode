class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int>ans;//creating a temporary array

        //pointers
        int i=0,j=0;

        //comapring elements of both the array
        while(i<m &&j<n){
            if(nums1[i]<=nums2[j])
            ans.push_back(nums1[i++]);
            else
            ans.push_back(nums2[j++]);
        }
        //remaining in 1
        while(i<m)
        ans.push_back(nums1[i++]);

        //remaining in 2
        while(j<n)
        ans.push_back(nums2[j++]);

        //store the merge in the nums back
        nums1=ans;
    }
};