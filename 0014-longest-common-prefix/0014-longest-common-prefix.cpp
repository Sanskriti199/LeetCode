class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        int a=strs.size();

        for(int i=1;i<a;i++){
            while(strs[i].find(ans)!=0)
            ans.pop_back();
        }
        return ans;
    }
};