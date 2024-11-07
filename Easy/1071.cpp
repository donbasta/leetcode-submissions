class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        int g = __gcd(n1, n2);
        int mx = 0;
        const auto check = [&](int idx, const string& s) -> bool {
            string check = s.substr(0, idx);
            bool ok = true;
            for (int i = 0; i < s.length(); i += idx) {
                ok &= (check == s.substr(i, idx));
            }
            return ok;
        };
        for (int i = 1; i * i <= g; i++) {
            if (g % i != 0) continue;
            for (auto c : {i, g / i}) {
                string a = str1.substr(0, c);
                string b = str2.substr(0, c);
                if (a != b) continue;
                if (check(c, str1) && check(c, str2)) {
                    mx = max(mx, c);
                }
            }
        }
        return str1.substr(0, mx);
    }
};