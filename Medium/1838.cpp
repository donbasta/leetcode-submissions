class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int M = 1e5;
        int freq[M + 1];
        memset(freq, 0, sizeof(freq));
        for (auto e : nums) freq[e]++;
        // vector<pair<int, int>> ve;
        vector<int> ve;
        for (int i = 1; i <= M; i++) {
            if (freq[i] == 0) continue;
            ve.emplace_back(i);
            // ve.emplace_back(i, freq[i]);
        }

        int ret = 0;
        for (int i = 0; i < ve.size(); i++) {
            // int cur = ve[i].second;
            int cur = freq[ve[i]];
            long long sisa = k;
            for (int j = i - 1; j >= 0; j--) {
                long long tam = 1ll * (ve[i] - ve[j]) * freq[ve[j]];
                // long long tam = 1ll * (ve[i].first - ve[j].first) * ve[j].second;
                if (tam <= sisa) {
                    sisa -= tam;
                    // cur += ve[j].second;
                    cur += freq[ve[j]];
                    if (sisa == 0) break;
                } else {
                    cur += sisa / (ve[i] - ve[j]);
                    // cur += sisa / (ve[i].first - ve[j].first);
                    break;
                }
            }
            ret = max(ret, cur);
        }

        return ret;
    }
};