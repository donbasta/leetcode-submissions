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
};


class StreamChecker {
public:
    Trie *tree = NULL;
    string stream;

    StreamChecker(vector<string>& words) {
        tree = new Trie();
        for (auto word : words) {
            reverse(word.begin(), word.end());
            tree->insert(word);
        }
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        int n = stream.length();
        Trie *curNode = tree;
        for (int i = 0; i < 200; i++) {
            if (i > n - 1) break;
            if (curNode->children.find(stream[n - 1 - i]) == curNode->children.end()) {
                return false;
            }
            curNode = curNode->children[stream[n - 1 - i]];
            if (curNode->endChar) return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */