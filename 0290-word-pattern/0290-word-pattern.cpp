class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);

        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string currentWord = words[i];

            if (charToWord.count(ch) && charToWord[ch] != currentWord) {
                return false;
            }

            if (wordToChar.count(currentWord) && wordToChar[currentWord] != ch) {
                return false;
            }

            charToWord[ch] = currentWord;
            wordToChar[currentWord] = ch;
        }

        return true;
    }
};