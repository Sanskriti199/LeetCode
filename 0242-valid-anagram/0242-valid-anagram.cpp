class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> count;

        for (char ch : s) {
            count[ch]++;
        }

        for (char ch : t) {
            count[ch]--;

            if (count[ch] < 0) {
                return false;
            }
        }

        return true;
    }
};