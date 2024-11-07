/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        const int M = 1000;
        vector<vector<int>> ve(M + 1);
        const function<void(Node*, int)> dfs = [&](Node* v, int depth) -> void {
            if (v == nullptr) return;
            ve[depth].push_back(v->val);
            for (auto c : v->children) {
                dfs(c, depth + 1);
            }
        };
        dfs(root, 0);
        for (int i = M; i >= 0; i--) {
            if (!ve[i].empty()) break;
            ve.pop_back();
        }
        return ve;
    }
};