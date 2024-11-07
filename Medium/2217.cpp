class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        using ll = long long;
        vector<ll> ret;
        // 100 - 999
        ll p10 = 1;
        for (int i = 1; i <= (intLength - 1) / 2; i++) p10 *= 10;
        ll cnt = p10 * 9;
        for (auto q : queries) {
            if (1ll * q > cnt) {
                ret.push_back(-1);
            } else {
                string x = to_string(p10 - 1 + q);
                int r = (int)x.length() - 1;
                if (intLength & 1) --r;
                for (int i = r; i >= 0; i--) {
                    x.push_back(x[i]);
                }
                ret.push_back(stoll(x));
            }
        }
        return ret;
    }
};