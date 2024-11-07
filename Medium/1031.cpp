class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        int curSec = 0;
        multiset<int> ki, ka;
        vector<int> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + nums[i];
        for (int i = 0; i < secondLen - 1; i++) {
            curSec += nums[i];
        }
        auto get = [&](int a, int b) {
            return pref[b] - (a ? pref[a - 1] : 0);
        };
        for (int i = secondLen; i + firstLen - 1 < n; i++) {
            ka.insert(get(i, i + firstLen - 1));
        }
        int ans = 0;
        for (int i = secondLen - 1; i < n; i++) {
            curSec += nums[i];
            int x = 0;
            if (!ki.empty()) {
                x = max(x, *ki.rbegin());
            }
            if (!ka.empty()) {
                x = max(x, *ka.rbegin());
            }
            ans = max(ans, x + curSec);
            curSec -= nums[i - secondLen + 1];
            if (i - secondLen - firstLen + 2 >= 0)
                ki.insert(get(i - secondLen - firstLen + 2, i - secondLen + 1));
            if (i + firstLen < n)
                ka.erase(ka.find(get(i + 1, i + firstLen)));
        }
        return ans;
    }
};