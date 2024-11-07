class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        using ll = long long;
        const int M = 5e4;
        vector<ll> cnt(M + 1), mul(M + 1), fpb_pair(M + 1);
        for (auto e : nums) {
            cnt[e]++;
        }
        for (int i = 1; i <= M; i++) {
            for (int j = i; j <= M; j += i) {
                mul[i] += cnt[j];
            }
        }
        for (int i = M; i >= 1; i--) {
            fpb_pair[i] = mul[i] * (mul[i] - 1) / 2;
            for (int j = i + i; j <= M; j += i) {
                fpb_pair[i] -= fpb_pair[j];
            }
        }
        vector<ll> pref(M + 1);
        pref[1] = fpb_pair[1];
        for (int i = 2; i <= M; i++) {
            pref[i] = (pref[i - 1] + fpb_pair[i]);
        }
        // for (int i = 1; i <= 5; i++) {
        //     cout << fpb_pair[i] << ' ';
        // }
        // cout << '\n';
        vector<int> ans;
        for (auto q : queries) {
            q++;
            int lo = 1, hi = M, piv = -1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (pref[mid] < q) {
                    lo = mid + 1;
                } else {
                    piv = mid;
                    hi = mid - 1;
                }
            }
            ans.push_back(piv);
        }
        return ans;
    }
};