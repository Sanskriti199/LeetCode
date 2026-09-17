class Solution {
public:
string minWindow(string s, string t) {
        if (t.empty() || s.length() < t.length()) {
            return "";
        }
        vector<int> required(128, 0);
        for (char c : t) {
            required[c]++;
        }

        int required_count = t.length();
        int formed_count = 0;
        vector<int> window(128, 0);

        int left = 0;
        int min_len = INT_MAX;
        int min_start = 0;

        for (int right = 0; right < s.length(); ++right) {
            char r_char = s[right];

            window[r_char]++;
            if (required[r_char] > 0 && window[r_char] <= required[r_char]) {
                formed_count++;
            }

            while (formed_count == required_count) {
                int current_len = right - left + 1;
                if (current_len < min_len) {
                    min_len = current_len;
                    min_start = left;
                }

                char l_char = s[left];
                
                window[l_char]--;

                if (required[l_char] > 0 && window[l_char] < required[l_char]) {
                    formed_count--;
                }

                left++;
            }
        }
        return (min_len == INT_MAX) ? "" : s.substr(min_start, min_len);
    }
};