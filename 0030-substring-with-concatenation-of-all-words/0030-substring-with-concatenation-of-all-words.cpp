class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int wordLen = words[0].size();
        int totalWords = words.size();
        int totalLen = wordLen * totalWords;

        if (s.size() < totalLen)
            return ans;

        unordered_map<string, int> need;

        for (string word : words)
            need[word]++;

        for (int start = 0; start < wordLen; start++) {
            int left = start;
            int count = 0;
            unordered_map<string, int> seen;

            for (int right = start; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);

                if (need.find(word) == need.end()) {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                seen[word]++;
                count++;

                while (seen[word] > need[word]) {
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    left += wordLen;
                    count--;
                }

                if (count == totalWords) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};