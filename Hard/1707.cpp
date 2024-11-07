struct Node {
    Node* ch[2];
    int cnt;
    Node() {ch[0] = ch[1] = nullptr;}
};

struct Trie {
    Node* head;
    bool empty;
    Trie() {
        empty = true;
        head = new Node();
    }
    void insert(int val) {
        empty = false;
        Node* cur = head;
        for (int i = 30; i >= 0; i--) {
            int cbit = (val >> i) & 1;
            if (!cur->ch[cbit]) {
                cur->ch[cbit] = new Node();
            }
            cur = cur->ch[cbit];
        }
    }
    int max_xor_with(int val) {
        if (empty) {
            return -1;
        }

        int ret = 0;
        Node* cur = head;
        for (int i = 30; i >= 0; i--) {
            int cbit = (val >> i) & 1;
            if (cur->ch[cbit ^ 1]) {
                ret ^= (1 << i);
                cur = cur->ch[cbit ^ 1];
            } else {
                cur = cur->ch[cbit];
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> q_id;
        for (int i = 0; i < queries.size(); i++) {
            q_id.push_back(vector<int>{queries[i][1], queries[i][0], i});
        }
        sort(q_id.begin(), q_id.end());
        sort(nums.begin(), nums.end());

        Trie tr;
        int itr = 0;
        vector<int> ret(queries.size());
        for (auto e : nums) {
            while (itr < queries.size() && q_id[itr][0] < e) {
                ret[q_id[itr][2]] = tr.max_xor_with(q_id[itr][1]);
                itr++;
            }
            tr.insert(e);
        }
        while (itr < queries.size()) {
            ret[q_id[itr][2]] = tr.max_xor_with(q_id[itr][1]);
            itr++;
        }
        return ret;
    }
};