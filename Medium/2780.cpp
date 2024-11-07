class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int n = nums.size();
        int dom = -1;
        int occ = 0;
        for (auto e : nums) cnt[e]++;
        for (auto e : cnt) {
            if (e.second * 2 > n) {
                occ = e.second;
                dom = e.first;
                break;
            }
        }
        assert (dom != -1);
        vector<int> pref(n);
        for (int i = 0; i < n; i++) {
            pref[i] = ((nums[i] == dom) + (i ? pref[i - 1] : 0));
        }
        for (int i = 0; i < n - 1; i++) {
            int x = pref[i];
            int y = occ - pref[i];
            bool ok_x = (x * 2) > (i + 1);
            bool ok_y = (y * 2) > (n - i - 1);
            if (ok_x && ok_y) {
                return i;
            }
        }
        return -1;
    }
};