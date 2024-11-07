class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        auto sum_digit = [&](int x) -> int {
            int ret = 0;
            while (x) {
                ret += x % 10;
                x /= 10;
            }
            return ret;
        };
        for (auto c : nums) {
            mp[sum_digit(c)].push_back(c);
        }
        int ans = -1;
        for (auto e : mp) {
            if (e.second.size() <= 1) continue;
            sort(e.second.begin(), e.second.end());
            ans = max(ans, e.second.back() + e.second[e.second.size() - 2]);
        }
        return ans;
    }
};