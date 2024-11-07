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
class BSTIterator {
public:
    vector<int> ve;
    int cur;

    BSTIterator(TreeNode* root) {
        vector<int> tmp;
        const function<void(TreeNode*)> init = [&](TreeNode* v) -> void {
            if (!v) return;
            init(v->left);
            tmp.emplace_back(v->val);
            init(v->right);
        };
        init(root);
        ve = tmp;
        cur = -1;
    }
    
    int next() {
        return ve[++cur];
    }
    
    bool hasNext() {
        return cur + 1 < (ve.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */