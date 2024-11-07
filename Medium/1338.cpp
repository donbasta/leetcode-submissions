class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int MX = 1e5;
        vector<int> cnt(MX + 1);
        for (auto e : arr) cnt[e]++;
        sort(cnt.begin(), cnt.end(), greater<>());
        int tot = 0;
        int n = arr.size();
        int idx = 0;
        while ((idx < n) && (tot < (n / 2))) {
            tot += cnt[idx++];
        }
        return idx;
    }
};