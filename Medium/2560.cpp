class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        vector<pair<int, int>> hehe;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            hehe.emplace_back(nums[i], i);
        }
        sort(hehe.begin(), hehe.end());
        set<pair<int, int>> intervals;
        int muat = 0;
        for (int i = 0; i < n; i++) {
            int newPos = hehe[i].second;
            int kiri = newPos, kanan = newPos;
            bool buangKanan = false, buangKiri = false;
            auto lol = intervals.lower_bound(make_pair(newPos + 1, newPos + 1));
            if (lol != intervals.end()) {
                if (lol->first == newPos + 1) {
                    // merge
                    kanan = lol->second;
                    buangKanan = true;
                    muat -= (lol->second - lol->first + 2) / 2;
                }
            }
            if (lol != intervals.begin()) {
                --lol;
                if (lol->second == newPos - 1) {
                    // merge
                    kiri = lol->first;
                    buangKiri = true;
                    muat -= (lol->second - lol->first + 2) / 2;
                }
            }
            auto lol2 = intervals.lower_bound(make_pair(newPos + 1, newPos + 1));
            if (buangKanan) {
                intervals.erase(lol2);
            }
            if (buangKiri) {
                intervals.erase(lol);
            }
            intervals.emplace(kiri, kanan);
            muat += (kanan - kiri + 2) / 2;
            // for (auto e : intervals) {
            //     cout << e.first << ' ' << e.second << '\n';
            // }
            // cout << muat << '\n';
            if (i >= k - 1) {
                if (muat >= k) {
                    return hehe[i].first;
                }
            }
        }
        return -1;
    }
};