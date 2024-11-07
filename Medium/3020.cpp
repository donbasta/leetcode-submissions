class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> cnt, rt;
        for (auto e : nums) cnt[e]++;
        for (auto e : nums) {
            int tmp = sqrtl(e);
            if (tmp * tmp == e) rt[e] = tmp;
            else rt[e] = -1;
        }
        int ans = 1;
        for (auto e : nums) {
            if (e == 1) {
                int lol = cnt[1];
                if (lol % 2 == 0) lol--;
                ans = max(ans, lol);
                continue;
            }
            int tmp = 1, now = e;
            while (rt[now] != -1 && cnt[rt[now]] >= 2) {
                tmp += 2, now = rt[now];
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};