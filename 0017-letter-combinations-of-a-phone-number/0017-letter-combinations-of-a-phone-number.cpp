class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        unordered_map<char, string> letterMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };
        
        vector<string> result;
        backtrack(0, "", digits, letterMap, result);
        return result;
    }
    
private:
    void backtrack(int index, string current, const string& digits, 
                   const unordered_map<char, string>& letterMap, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        char digit = digits[index];
        string letters = letterMap.at(digit);
        
        for (char letter : letters) {
            backtrack(index + 1, current + letter, digits, letterMap, result);
}
    }
};
