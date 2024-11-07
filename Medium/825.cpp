class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(121), pre(121);
        for (auto e : ages) cnt[e]++;
        for (int i = 1; i <= 120; i++) {
            pre[i] = pre[i - 1] + cnt[i];
        }
        int ans = 0;
        for (int i = 1; i <= 120; i++) {
            int atas = i;
            int bawah = (i / 2) + 8;
            if (atas < bawah) continue;
            ans += cnt[i] * (pre[atas] - pre[bawah - 1] - 1);
        }
        return ans;
    }
};