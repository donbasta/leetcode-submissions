class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> pref(n); 
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }
        long long ans = 1e18;

        vector<int> pw(10);
        pw[0] = 1;
        for (int i = 1; i <= 9; i++) {
            pw[i] = pw[i - 1] * 10;
        }
        auto palindromes = [&](int len) -> vector<int> {
            int pref = (len + 1) / 2;
            vector<int> ret;
            for (int i = pw[pref - 1]; i <= pw[pref] - 1; i++) {
                string ss = to_string(i);
                for (int i = len / 2 - 1; i >= 0; i--) {
                    ss += ss[i];
                }
                ret.push_back(stoi(ss));
            }
            return ret;
        };
        
        int idx = 0;
        for (int i = 1; i <= 9; i++) {
            vector<int> pal = palindromes(i);
            bool done = false;
            for (auto si : pal) {
                while (idx < n && nums[idx] < si) idx++;
                long long cur = 1ll * idx * si - (idx ? pref[idx - 1] : 0ll);
                cur += (pref[n - 1] - (idx ? pref[idx - 1] : 0)) - (1ll * (n - idx) * si);
                ans = min(ans, cur);
                if (idx == n) {
                    done = true;
                    break;
                }
            }
            if (done) break;
        }
        return ans;
    }
};