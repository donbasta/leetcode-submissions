struct Trie {
    struct Node {
        int val;
        unordered_map<char, Node*> children;
        Node() {
            val = 0;
        }
    };

    Node* head;

    Trie() {head = new Node();}

    void insert(string key, int val) {
        Node* cur = head;
        cur->val += val;
        for (int i = 0; i < key.length(); i++) {
            if ((cur->children).find(key[i]) == (cur->children).end()) {
                (cur->children)[key[i]] = new Node();
            }
            cur = (cur->children)[key[i]];
            cur->val += val;
        }
    }

    int sum(string prefix) {
        Node* cur = head;
        for (int i = 0; i < prefix.length(); i++) {
            if ((cur->children).find(prefix[i]) == (cur->children).end()) {
                return 0;
            }
            cur = (cur->children)[prefix[i]];
        }
        return cur->val;
    }
};


class MapSum {
public:
    unordered_map<string, int> kv;
    Trie trie;

    MapSum() {
        
    }
    
    void insert(string key, int val) {
        int ori = 0;
        if (kv.find(key) != kv.end()) {
            ori = kv[key];
        }
        kv[key] = val;
        trie.insert(key, val - ori);
    }
    
    int sum(string prefix) {
        return trie.sum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */