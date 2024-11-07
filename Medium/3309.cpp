class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        vector<string> st(3);
        for (int i = 0; i < 3; i++) {
            while (nums[i]) {
                st[i].push_back((char)((nums[i] & 1) + '0'));
                nums[i] >>= 1;
            }
            reverse(st[i].begin(), st[i].end());
        }
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                for (int k = 0; k < 3; k++) {
                    if (i == k || j == k) continue;
                    string tmp = st[i] + st[j] + st[k];
                    int len = tmp.length();
                    int cur = 0;
                    for (int d = len - 1; d >= 0; d--) {
                        if (tmp[d] == '0') continue;
                        cur += (1 << (len - 1 - d));
                    }
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }
};