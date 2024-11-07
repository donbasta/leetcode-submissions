struct Trie {
    struct Node {
        unordered_map<char, Node*> child;
        int val;
        Node () {
            val = 0;
        }
    };

    Node* head;

    Trie() {head = new Node();}

    void insert(const string& s) {
        Node* cur = head;
        cur->val++;
        for (auto c : s) {
            if ((cur->child).find(c) == (cur->child).end()) {
                cur->child[c] = new Node();
            }
            cur = cur->child[c];
            cur->val++;
        }
    }

    int calc(const string& s) {
        Node* cur = head;
        int ans = 0;
        for (auto c : s) {
            cur = cur->child[c];
            ans += cur->val;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;
        for (auto word : words) {
            t.insert(word);
        }

        vector<int> ret;
        for (auto word : words) {
            ret.push_back(t.calc(word));
        } 
        return ret;
    }
};