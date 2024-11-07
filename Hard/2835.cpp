class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sum = 0;
        for (auto e : nums) sum += e;
        if (sum < 1ll * target) return -1;
        
        unordered_map<int, int> lmao;
        vector<int> cnt(31), need(31);
        int tmp = 1;
        for (int i = 0; i <= 30; i++) {
            lmao[tmp] = i;
            if (i < 30) tmp *= 2;
        }
        for (auto e : nums) {
            cnt[lmao[e]]++;
        }
        for (int i = 0; i <= 30; i++) {
            if ((target >> i) & 1) {
                need[i]++;
            }
        }
        int cur = 0;
        int ans = 0;
        for (int i = 0; i <= 30; i++) {
            if (need[i] == 0) continue;
            // cout << i << '\n';
            long long tmp = 0;
            for (int j = 0; j <= i; j++) {
                tmp += (1ll << j) * cnt[j];
            }
            if (tmp >= (1ll << i)) {
                // cout << i << '\n';
                need[i]--;
                for (int j = 1; j <= i; j++) {
                    cnt[j] += cnt[j - 1] / 2;
                    cnt[j - 1] %= 2;
                }
                assert(cnt[i] > 0);
                cnt[i]--;
            } else {
                // cout << i << '\n';
                need[i]--;
                int start;
                for (int j = i + 1; j <= 30; j++) {
                    if (cnt[j] > 0) {
                        start = j;
                        break;
                    }
                }
                cnt[start]--;
                ans += (start - i);
                for (int j = start - 1; j >= i; j--) {
                    cnt[j]++;
                }
            }
        }
        for (int i = 30; i >= 0; i--) {
            if (need[i] == 0) continue;
            int start;
            for (int j = i; j <= 30; j++) {
                if (cnt[j] > 0) {
                    start = j;
                    break;
                }
            }
            ans += (start - i);
            for (int j = start - 1; j >= i; j--) {
                cnt[j]++;
            }
        }
        return ans;


    }
};