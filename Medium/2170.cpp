class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (n == 2) return (nums[0] == nums[1]);
        const int MX = 1e5;
        pair<int, int> cnt[2][MX + 1];
        for (int j = 0; j < 2; j++) {
            int tmp[MX + 1];
            memset(tmp, 0, sizeof(tmp));
            for (int i = j; i < n; i += 2) {
                tmp[nums[i]]++;
            }
            int idx = 0;
            for (int i = 1; i <= MX; i++) {
                if (tmp[i] == 0) continue;
                cnt[j][idx++] = make_pair(tmp[i], i);
            }
            cnt[j][idx] = make_pair(0, 0);
            sort(cnt[j], cnt[j] + idx, greater<>());
        }
        int ans;
        if (cnt[0][0].second != cnt[1][0].second) {
            ans = n - (cnt[0][0].first + cnt[1][0].first);
        } else {
            ans = min(n - (cnt[0][0].first + cnt[1][1].first), n - (cnt[0][1].first + cnt[1][0].first));
        } 
        return ans;
    }
};