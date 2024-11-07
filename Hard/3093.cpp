struct Node {
    unordered_map<char, Node*> chd;
    pair<int, int> best;
    Node() {
        best = make_pair(10000, -1);
    }
};

struct Trie {
    Node* head;
    Trie() {
        head = new Node();
    }
    void insert(const string& s, int idx) {
        Node* cur = head;
        cur->best = min(cur->best, make_pair((int)s.length(), idx));
        for (auto c : s) {
            if (cur->chd.find(c) == cur->chd.end()) {
                cur->chd[c] = new Node();
            }
            cur = cur->chd[c];
            cur->best = min(cur->best, make_pair((int)s.length(), idx));
        }
    }
    int get(const string& s) {
        Node* cur = head;
        for (auto c : s) {
            if (cur->chd.find(c) == cur->chd.end()) {
                return cur->best.second;
            } else {
                cur = cur->chd[c];
            }
        }
        return cur->best.second;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie;
        int n = wordsContainer.size();
        for (int i = 0; i < n; i++) {
            string w = wordsContainer[i];
            reverse(w.begin(), w.end());
            trie.insert(w, i);
        }
        vector<int> ret;
        for (auto w : wordsQuery) {
            reverse(w.begin(), w.end());
            ret.push_back(trie.get(w));
        }
        return ret;
    }
};