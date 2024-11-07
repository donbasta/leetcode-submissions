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
    vector<int> preorder(Node* root) {
        vector<int> ret;
        if (!root) return ret;

        function<void(Node*)> dfs = [&](Node* v) {
            ret.push_back(v->val);
            for (auto c : v->children) {
                dfs(c);
            }
        };

        dfs(root);
        return ret;
    }
};