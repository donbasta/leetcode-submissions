struct Node {
    Node* ch[2];
    int cnt;
    Node() : cnt(0) {ch[0] = ch[1] = nullptr;}
};

struct Trie {
    Node* head;
    Trie() {
        head = new Node();
    }
    void insert(int val) {
        Node* cur = head;
        cur->cnt++;
        for (int i = 16; i >= 0; i--) {
            int cbit = (val >> i) & 1;
            if (!cur->ch[cbit]) {
                cur->ch[cbit] = new Node();
            }
            cur = cur->ch[cbit];
            cur->cnt++;
        }
    }
    int query(int num, int val) {
        Node* cur = head;
        int ret = 0;
        for (int i = 16; i >= 0; i--) {
            int abit = (num >> i) & 1;
            int cbit = (val >> i) & 1;
            if (cbit == 0) {
                cur = cur->ch[abit];
            } else {
                if (cur->ch[abit]) {
                    ret += cur->ch[abit]->cnt;
                }
                cur = cur->ch[abit ^ 1];
            }
            if (!cur) break;
        }
        if (cur) ret += cur->cnt;
        return ret;
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        using ll = long long;
        int n = nums.size();
        const function<ll(int)> F = [&](int bat) -> ll {
            Trie tr;
            ll ret = 0;
            for (int i = n - 1; i >= 0; i--) {
                int tmp = tr.query(nums[i], bat);
                ret += tmp;
                tr.insert(nums[i]);
            }
            return ret;
        };

        return F(high) - F(low - 1);
    }
};