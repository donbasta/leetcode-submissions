class WordDictionary {
public:
    unordered_map<string, bool> dict;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        int n = word.length();
        dict[word] = true;
        for (int i = 0; i < n; i++) {
            char tmp = word[i];
            word[i] = '.';
            dict[word] = true;
            word[i] = tmp;
        }
    }
    
    bool search(string word) {
        vector<int> dotpos;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            if (word[i] == '.') dotpos.push_back(i);
            if (dotpos.size() >= 2) break;
        }
        if (dotpos.size() <= 1) return dict.find(word) != dict.end();
        else if (dotpos.size() == 2) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    word[dotpos[0]] = (char) (i + 'a');
                    word[dotpos[1]] = (char) (j + 'a');
                    if (dict.find(word) != dict.end()) return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */