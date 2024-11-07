struct Trie {
    struct Node {
        vector<Node*> ve;
        Node() {
            ve.resize(2);
            ve[0] = ve[1] = nullptr;
        }
    };

    Node* head;

    Trie() {head = new Node();}

    void insert(int x) {
        Node* cur = head;
        for (int i = 30; i >= 0; i--) {
            int dig = (x >> i) & (1);
            if (!cur->ve[dig]) cur->ve[dig] = new Node();
            cur = cur->ve[dig];
        }
    }

    int query(int x) {
        Node* cur = head;
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            int dig = (x >> i) & 1;
            if (cur->ve[dig ^ 1]) {
                ans += (1 << i);
                cur = cur->ve[dig ^ 1];
            } else {
                cur = cur->ve[dig];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (auto e : nums) {
            trie.insert(e);
        }
        int ans = 0;
        for (auto e : nums) {
            ans = max(ans, trie.query(e));
        }
        return ans;
    }
};