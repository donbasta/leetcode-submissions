/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "()";
        string ret = "(";
        ret += to_string(root->val);
        ret += serialize(root->left);
        ret += serialize(root->right);
        ret += ")";
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "()") return nullptr;
        int val = -1;
        int start = -1;
        int n = data.length();
        for (int i = 1; i < n; i++) {
            if (data[i] == '(') {
                val = stoi(data.substr(1, i - 1));
                start = i;
                break;
            }
        }
        assert (val != -1);
        assert (start != -1);
        TreeNode* ret = new TreeNode(val);
        int cur = 0;
        for (int i = start; i < n; i++) {
            if (data[i] == '(') cur++;
            else if (data[i] == ')') cur--;
            if (cur == 0) {
                ret->left = deserialize(data.substr(start, i - start + 1));
                ret->right = deserialize(data.substr(i + 1, n - 2 - i));
                break;
            }
        }
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;