class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        using ll = long long;
        ll L = stoll(left), R = stoll(right);
        int ans = 0;

        auto is_pali = [&](ll x) -> bool {
            string s = to_string(x);
            int len = s.length();
            for (int i = 0; i < len / 2; i++) {
                if (s[i] != s[len - 1 - i]) return false;
            }
            return true;
        };

        for (ll i = 1; ; i++) {
            string s = to_string(i);
            string cs = s;
            reverse(cs.begin(), cs.end());
            s += cs;
            ll ns = stoll(s);
            if (ns >= R / ns + 1) break;
            ans += ns * ns >= L && is_pali(ns * ns);
        }
        for (ll i = 1; ; i++) {
            string s = to_string(i);
            string cs = s;
            cs.pop_back();
            reverse(cs.begin(), cs.end());
            s += cs;
            ll ns = stoll(s);
            if (ns >= R / ns + 1) break;
            ans += ns * ns >= L && is_pali(ns * ns);
        }
        return ans;
    }
};