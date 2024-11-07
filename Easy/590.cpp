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
    vector<int> postorder(Node* root) {
        vector<int> ret;
        if (!root) return ret;
        for (auto c : root->children) {
            vector<int> tmp = postorder(c);
            for (auto x : tmp) {
                ret.push_back(x);
            }
        }
        ret.push_back(root->val);
        return ret;
    }
};