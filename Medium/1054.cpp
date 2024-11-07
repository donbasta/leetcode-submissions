class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> cnt;
        for (auto e : barcodes) cnt[e]++;
        sort (barcodes.begin(), barcodes.end(), [&](int a, int b) -> bool {
            if (cnt[a] == cnt[b]) return a < b;
            return cnt[a] > cnt[b];
        });
        int n = barcodes.size();
        vector<int> ret(n);
        int idx = 0;
        for (int i = 0; i < n; i += 2) ret[i] = barcodes[idx++];
        for (int i = 1; i < n; i += 2) ret[i] = barcodes[idx++];
        return ret;
    }
};