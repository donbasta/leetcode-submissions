class Solution {
public:
    bool is_cyclic(const vector<int>& elems, unordered_map<int, vector<int>>& graph) {
        unordered_map<int, int> col;
        const function<bool(int)> dfs = [&](int v) -> bool {
            col[v] = 1;
            for (auto c : graph[v]) {
                if (col[c] == 0) {
                    if (dfs(c)) return true;
                } else if (col[c] == 1) {
                    return true;
                }
            }
            col[v] = 2;
            return false;
        };
        for (auto e : elems) {
            if (col[e] == 2) continue;
            if (dfs(e)) return true;
        }
        return false;
    }

    vector<int> find_topo(const vector<int>& elems, unordered_map<int, vector<int>>& graph) {
        vector<int> ret;
        unordered_map<int, bool> vis;
        const function<void(int)> dfs = [&](int v) -> void {
            vis[v] = true;
            for (auto c : graph[v]) {
                if (vis[c]) continue;
                dfs(c);
            }
            ret.push_back(v);
        };
        for (auto e : elems) {
            if (vis[e]) continue;
            dfs(e);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int, vector<int>> before_groups;
        // -1 is treated as its own group
        vector<vector<int>> elements(m);
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                elements.push_back({i});
                group[i] = m;
                m++;
            } else {
                elements[group[i]].push_back(i);
            }
        }
        vector<unordered_map<int, vector<int>>> before_items_in_group(m);
        for (int i = 0; i < n; i++) {
            int y = group[i];
            for (auto e : beforeItems[i]) {
                int x = group[e];
                if (x == y) {
                    before_items_in_group[x][e].push_back(i);
                } else {
                    before_groups[x].push_back(y);
                }
            }
        }
        vector<int> ret;
        // find group_order
        vector<int> tmp(m); iota(tmp.begin(), tmp.end(), 0);
        if (is_cyclic(tmp, before_groups)) return {};
        vector<int> group_order = find_topo(tmp, before_groups);
        for (auto e : group_order) {
            if (is_cyclic(elements[e], before_items_in_group[e])) return {};
            vector<int> item_order_in_group = find_topo(elements[e], before_items_in_group[e]);
            for (auto item : item_order_in_group) ret.push_back(item);
        }
        return ret;
    }
};