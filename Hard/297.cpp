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
        string ret;
        ret.push_back('(');
        ret += serialize(root->left);
        ret += ',';
        ret += to_string(root->val);
        ret += ',';
        ret += serialize(root->right);
        ret.push_back(')');
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "()") return nullptr;
        TreeNode* ret = new TreeNode(-1);
        int bruh = 2;
        bool leftFound = false;
        string tmpVal;
        for (int i = 2; i < data.length(); i++) {
            if (data[i] == ')') {
                bruh--;
                if (bruh == 1) {
                    ret->left = deserialize(data.substr(1, i));
                    leftFound = true;
                }
            } else if (data[i] == '(') {
                if (leftFound) {
                    ret->right = deserialize(data.substr(i, data.length() - 1 - i));
                    break;
                }
                bruh++;
            } else if (leftFound) {
                tmpVal.push_back(data[i]);
            }
        }
        ret->val = stoi(tmpVal.substr(1, tmpVal.length() - 2));
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));