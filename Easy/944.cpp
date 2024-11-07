class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int len = strs[0].length();
        int ret = 0;
        for (int i = 0; i < len; i++) {
            bool ok = false;
            for (int j = 1; j < (int)strs.size(); j++) {
                if (strs[j][i] < strs[j - 1][i]) {
                    ok = true;
                    break;
                }
            }
            ret += ok;
        }

        return ret;
    }
};