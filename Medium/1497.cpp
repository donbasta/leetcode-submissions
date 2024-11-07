class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> cnt(k);
        for (auto e : arr) {
            int rem = e % k;
            if (rem < 0) rem += k;
            cnt[rem]++;
        }
        for (int i = 0; i < k; i++) {
            int oth = (k - i) % k;
            if (i == oth) {
                if (cnt[i] & 1) return false;
            }
            if (oth < i) continue;
            if (cnt[i] != cnt[oth]) return false;
        }
        return true;
    }
};