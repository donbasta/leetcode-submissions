/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        unordered_map<int, Node*> cur;
        const function<void(Node*, int)> dfs = [&](Node *v, int depth) -> void {
            if (v == nullptr) return;
            if (cur[depth] != nullptr) {
                cur[depth]->next = v;
            }
            cur[depth] = v;
            dfs(v->left, depth + 1);
            dfs(v->right, depth + 1);
        };
        dfs(root, 0);
        return root;
    }
};