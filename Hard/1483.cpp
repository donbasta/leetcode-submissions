struct LCA {
    vector<int> tin, tout, par, depth;
    int timer, len;
    vector<vector<int>> up, adj;

    LCA() {}

    LCA(int n, vector<vector<int>>& adj) : adj(adj) {
        tin.resize(n);
        tout.resize(n);
        par.resize(n);
        depth.resize(n);
        timer = 0;
        len = ceil(log2(n));
        up.assign(n, vector<int>(len + 1));
        dfs(0, 0);
    }

    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= len; i++) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (auto c : adj[v]) {
            if (c == p) continue;
            par[c] = v;
            depth[c] = depth[v] + 1;
            dfs(c, v);
        }
        tout[v] = ++timer;
    }

    int get_kth_ancestor(int u, int k) {
        if (depth[u] < k) return -1; //depth of u is less than k, no kth ancestor
        int cur = 0;
        int ret = u;
        for (int i = len; i >= 0; i--) {
            if (cur + (1 << i) > k) continue;
            cur += (1 << i);
            ret = up[ret][i];
        }
        return ret;
    }
};

class TreeAncestor {
public:
    LCA tree;

    TreeAncestor(int n, vector<int>& parent) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < parent.size(); i++) {
            if (i == 0) continue;
            adj[parent[i]].emplace_back(i);
            adj[i].emplace_back(parent[i]);
        }
        tree = LCA(n, adj);
    }
    
    int getKthAncestor(int node, int k) {
        if (tree.depth[node] < k) return -1;
        return tree.get_kth_ancestor(node, k);
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */