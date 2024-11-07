/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct Segtree {
    vector<int> tree;
    Segtree(int n) {
        tree.resize(4 * n + 5);
    }
    void build(int v, int s, int e, const vector<int>& ar) {
        if (s == e) {
            tree[v] = ar[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, ar);
        build(v << 1 | 1, mid + 1, e, ar);
        tree[v] = max(tree[v << 1], tree[v << 1 |1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid) return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return get(v << 1 | 1, mid + 1, e, l, r);
        return max(get(v << 1, s, mid, l, mid), get(v << 1 |1, mid + 1, e, mid + 1, r));
    }
};

class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> tin, tout, depth;
        int time = 0;
        const function<void(TreeNode*)> dfs = [&](TreeNode* t) -> void {
            tin[t->val] = time++;
            if (t->left) depth[t->left->val] = depth[t->val] + 1, dfs(t->left); 
            if (t->right) depth[t->right->val] = depth[t->val] + 1, dfs(t->right); 
            tout[t->val] = time++;
        };
        dfs(root);
        int n = depth.size();
        assert (n * 2 == time);
        vector<int> dfs_table(n * 2);
        for (int i = 1; i <= n; i++) {
            dfs_table[tin[i]] = dfs_table[tout[i]] = depth[i];
        }
        Segtree sgt(n * 2);
        sgt.build(1, 0, 2 * n - 1, dfs_table);
        vector<int> ret;
        for (auto q : queries) {
            int s = tin[q], e = tout[q];
            int le = (s - 1 >= 0) ? sgt.get(1, 0, 2 * n - 1, 0, s - 1) : 0;
            int ri = (e + 1 <= 2 * n - 1) ? sgt.get(1, 0, 2 * n - 1, e + 1, 2 * n - 1) : 0;
            ret.push_back(max(le, ri));
        }
        return ret;
    }
};