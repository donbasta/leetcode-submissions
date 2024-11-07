class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> ar;
        for (int i = 0; i < n; i++) {
            int cnt[26];
            memset(cnt, 0, sizeof(cnt));
            for (auto e : arr[i]) cnt[e - 'a']++;
            int tmp = 0;
            bool cant = false;
            for (int j = 0; j < 26; j++) {
                if (cnt[j] > 1) {
                    cant = true;
                    break;
                }
                if (cnt[j] > 0) {
                    tmp ^= (1 << j);
                }
            }
            if (!cant) {
                ar.push_back(tmp);
            }
        }
        int m = ar.size();
        int ans = 0;
        for (int mask = 1; mask < (1 << m); mask++) {
            int chars = 0;
            bool can = true;
            for (int j = 0; j < m; j++) {
                if ((mask >> j) & 1) {
                    if (chars & ar[j]) {
                        can = false;
                        break;
                    }
                    chars ^= ar[j];
                }
            }
            if (!can) continue;
            ans = max(ans, __builtin_popcount(chars));
        }
        return ans;
    }
};