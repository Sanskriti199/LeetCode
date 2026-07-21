class Solution {
public:
    int lengthOfLongestSubstring(string m) {
        int n=m.length();
        int t=0;
        unordered_set<char>charSet;
        int l=0;

        for(int r=0;r<n;r++){
            if(charSet.count(m[r])==0){
                charSet.insert(m[r]);
                t=max(t,r-l+1);
            }
            else{
                while(charSet.count(m[r])){
                    charSet.erase(m[l]);
                    l++;
                }
                charSet.insert(m[r]);
            }
        }
        return t;
    }
};