class Trie {
public:
    bool endChar;
    unordered_map<char, Trie*> children;
    
    Trie() {
        endChar = false;
    }
    
    void insert(string word) {
        int n = word.length();
        Trie* cur = this;
        for (int i = 0; i < n; i++) {
            if (cur->children.find(word[i]) == cur->children.end()) {
                Trie* newChild = new Trie();
                if (i == n - 1) {
                    newChild->endChar = true;
                }
                cur->children[word[i]] = newChild;
                cur = newChild;
            } else {
                if (i == n - 1) {
                    cur->children[word[i]]->endChar = true;
                }
                cur = cur->children[word[i]];
            }
        }
    }

    bool search(string word) {
        int n = word.length();
        Trie* cur = this;
        for (int i = 0; i < n; i++) {
            if (cur->children.find(word[i]) == cur->children.end()) {
                return false;
            }
            if (i == n - 1 && !cur->children[word[i]]->endChar) {
                return false;
            }
            cur = cur->children[word[i]];
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.length();
        Trie* cur = this;
        for (int i = 0; i < n; i++) {
            if (cur->children.find(prefix[i]) == cur->children.end()) {
                return false;
            }
            cur = cur->children[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */