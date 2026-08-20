class Solution {
public:
    bool isSubsequence(string s, string t) {
    //two pointers
     int i=0;
     int j=0;

    //storing the lengths
     int n=s.length();
     int m=t.length();

     while(i<n &&j<m){
        if(s[i]==t[j]){
            i++;
        }
        j++;
     }
     return i==n;
    }
};