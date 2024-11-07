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
        for (int i = 30; i >= 0; i--) {
            int cbit = (val >> i) & 1;
            if (!cur->ch[cbit]) {
                cur->ch[cbit] = new Node();
            }
            cur = cur->ch[cbit];
            cur->cnt++;
        }
    }
    void erase(int val) {
        Node* cur = head;
        cur->cnt--;
        for (int i = 30; i >= 0; i--) {
            int cbit = (val >> i) & 1;
            assert (cur->ch[cbit]);
            cur = cur->ch[cbit];
            cur->cnt--;
        }
    }
    int max_xor_with(int val) {
        int ret = 0;
        Node* cur = head;
        for (int i = 30; i >= 0; i--) {
            int cbit = (val >> i) & 1;
            if (cur->ch[cbit ^ 1] && (cur->ch[cbit ^ 1]->cnt > 0)) {
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
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size();
        int root = -1;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) {
                root = i;
            } else {
                adj[i].push_back(parents[i]);
                adj[parents[i]].push_back(i);
            }
        }
        int q = queries.size();
        vector<int> ret(q);
        vector<vector<vector<int>>> queries_by_vert(n);
        for (int i = 0; i < q; i++) {
            queries_by_vert[queries[i][0]].push_back(vector<int>{queries[i][1], i});
        }

        Trie tr;
        const function<void(int, int)> dfs = [&](int v, int p) {
            tr.insert(v);
            for (auto Q : queries_by_vert[v]) {
                ret[Q[1]] = tr.max_xor_with(Q[0]);
            }
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs(c, v);
            }
            tr.erase(v);
        };
        dfs(root, root);
        return ret;
    }
};