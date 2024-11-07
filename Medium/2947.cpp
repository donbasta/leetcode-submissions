class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int kk = 1;
        for (int i = 2; i * i <= k; i++) {
            if (k % i != 0) continue;
            int pw = 0;
            while (k % i == 0) {
                k /= i, pw++;
            }
            int need = (pw + 1) / 2;
            for (int j = 0; j < need; j++) kk *= i;
        }
        if (k > 1) kk *= k;

        int n = s.length();
        vector<int> pref(n + 1);
        int cur = 0;
        vector<unordered_map<int, int>> cnt(kk * 2);
        cnt[0][0]++;

        auto is_vowel = [&](char c) -> bool {
            for (auto e : "aeiou") {
                if (e == c) return true;
            }
            return false;
        };
        for (int i = 0; i < n; i++) {
            cur = (is_vowel(s[i]) ? (cur + 1) : (cur - 1));
            cnt[(i + 1) % (kk * 2)][cur]++;
        }
        long long ans = 0;
        for (int i = 0; i < (kk * 2); i++) {
            for (auto c : cnt[i]) {
                ans += 1ll * c.second * (c.second - 1) / 2;
            }
        }
        return ans;
    }
};