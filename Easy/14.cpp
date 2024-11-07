class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string cp = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int idx = 0;
            while (idx < cp.size() && idx < strs[i].length() && cp[idx] == strs[i][idx]) {
                idx++;
            }
            cp = cp.substr(0, idx);
        }
        return cp;
    }
};