class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        const function<int(int)> lmao = [&](int x) -> int {
            string a = to_string(x);
            string b = a;
            reverse(b.begin(), b.end());
            int rev_x = stoi(b);
            return x - rev_x;
        };
        unordered_map<int, int> mp;
        for (auto e : nums) mp[lmao(e)]++;
        int ans = 0;
        const int MOD = 1e9 + 7;
        for (auto e : mp) {
            ans = (1ll * ans + (1ll * e.second * (e.second - 1)) / 2) % MOD;
        }
        return ans;
    }
};