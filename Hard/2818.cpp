class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prime_score(n);
        for (int i = 0; i < n; i++) {
            int ni = nums[i];
            for (int j = 2; j * j <= ni; j++) {
                if (ni % j != 0) continue;
                while (ni % j == 0) ni /= j;
                prime_score[i]++;
            }
            if (ni > 1) prime_score[i]++;
        }
        vector<int> le(n, -1), ri(n, n);
        vector<pair<int, int>> tmp;
        for (int i = 0; i < n; i++) {
            while (!tmp.empty() && prime_score[i] > tmp.back().first) {
                ri[tmp.back().second] = i;
                tmp.pop_back();
            }
            tmp.emplace_back(prime_score[i], i);
        }
        tmp.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!tmp.empty() && prime_score[i] >= tmp.back().first) {
                le[tmp.back().second] = i;
                tmp.pop_back();
            }
            tmp.emplace_back(prime_score[i], i);
        }
        vector<array<int, 4>> lmao(n);
        for (int i = 0; i < n; i++) {
            lmao[i] = {nums[i], le[i], ri[i], i};
        }
        
        const int MOD = 1e9 + 7;
        const function<int(int, int)> fpow = [&](int a, int b) -> int {
            int ret = 1;
            while (b) {
                if (b & 1) ret = (1ll * ret * a) % MOD;
                a = (1ll * a * a) % MOD;
                b >>= 1;
            }
            return ret;
        };
        
        int ans = 1;
        sort(lmao.begin(), lmao.end());
        for (int i = n - 1; i >= 0; i--) {
            long long avail = (lmao[i][3] - lmao[i][1]) * (lmao[i][2] - lmao[i][3]);
            int pw;
            if (avail >= (1ll * k)) {
                pw = k;
            } else {
                pw = avail;
            }
            ans = (1ll * ans * fpow(lmao[i][0], pw)) % MOD;
            if ((1ll * k) <= avail) break;
            k -= avail;
        }
        return ans;
    }
};