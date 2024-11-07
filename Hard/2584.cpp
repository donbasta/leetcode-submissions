class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return -1;
        map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 2; j * j <= nums[i]; j++) {
                if (nums[i] % j == 0) {
                    if (mp.find(j) == mp.end()) {
                        mp[j] = make_pair(i, i);
                    } else {
                        mp[j].second = i;
                    }
                    while (nums[i] % j == 0) {
                        nums[i] /= j;
                    }
                }
            }
            if (nums[i] > 1) {
                if (mp.find(nums[i]) == mp.end()) {
                    mp[nums[i]] = make_pair(i, i);
                } else {
                    mp[nums[i]].second = i;
                }
            }
        }
        vector<pair<int, int>> hehe;
        for (auto e : mp) {
            hehe.push_back(e.second);
        }
        if (hehe.size() == 0) return 0;
        sort(hehe.begin(), hehe.end());
        int l = hehe[0].first, r = hehe[0].second;
        if (l > 0) return 0;
        for (int i = 1; i < hehe.size(); i++) {
            int cl = hehe[i].first, cr = hehe[i].second;
            if (cl > r) {
                return r;
            }
            r = max(r, cr);
        }
        if (r <= n - 2) return r;
        return -1;
    }
};