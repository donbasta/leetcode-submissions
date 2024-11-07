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
        if (!root) return root;
        root->next = nullptr;
        connect(root->left);
        connect(root->right);
        Node* cur_left = root->left;
        Node* cur_right = root->right;
        while (cur_left && cur_right) {
            cur_left->next = cur_right;
            cur_left = cur_left->right;
            cur_right = cur_right->left;
        }
        return root;
    }
};