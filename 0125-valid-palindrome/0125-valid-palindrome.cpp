class Solution {
public:
    bool check(int i, string &s) {
    int n = s.length();

    if (i >= n / 2)
    return true;

    if (s[i] != s[n - i - 1])
    return false;

    return check(i + 1, s);
    }

    bool isPalindrome(string s) {
    string t;

    for (char c : s) {
    if (isalnum(c))
    t += tolower(c);
        }

    return check(0, t);
    }
};