class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        stringstream iss(s);
        string word;
        vector<string> line;

        while (iss >> word) {
            line.push_back(word);
        }

        if (n != line.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < n; i++) {
            char ch = pattern[i];
            string w = line[i];

            if (charToWord.find(ch) == charToWord.end() && wordToChar.find(w) == wordToChar.end()) {
                charToWord[ch] = w;
                wordToChar[w] = ch;
            } else {
                if (charToWord[ch] != w || wordToChar[w] != ch) {
                    return false;
                }
            }
        }
        return true;
    }
};
