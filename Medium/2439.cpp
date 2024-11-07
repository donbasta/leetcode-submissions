class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int le = 0, ri = *max_element(nums.begin(), nums.end());
        int ans = -1;
        const function<bool(int)> ok = [&](int x) -> bool {
            vector<long long> tmp;
            for (auto e : nums) tmp.push_back(e);
            for (int i = tmp.size() - 1; i >= 1; i--) {
                if (tmp[i] <= x) continue;
                else {
                    tmp[i - 1] += (tmp[i] - x);
                }
            }
            return tmp[0] <= x;
        };
        while (le <= ri) {
            int mid = (le + ri) >> 1;
            if (ok(mid)) {
                ans = mid;
                ri = mid - 1;
            } else {
                le = mid + 1;
            }
        }
        return ans;
    }
};