class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        vector<int> blocks;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cur++;
            } else {
                if (cur > 0) {
                    blocks.push_back(cur);
                    cur = 0;
                }
            }
        }
        int st = 1;
        int ans = 0;
        for (int i = (int) blocks.size() - 1; i >= 0; i--) {
            ans += st * blocks[i];
            st++;
        }
        return ans;
    }
};