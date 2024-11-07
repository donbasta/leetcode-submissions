class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        if (n == 1) return false;
        vector<int> div;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                div.push_back(i);
                if (i != (n / i)) div.push_back(n / i);
            }
        }
        div.push_back(1);
        sort(div.begin(), div.end());
        for (auto d : div) {
            string cek = s.substr(0, d);
            bool ok = true;
            for (int i = d; i < n; i += d) {
                if (cek != s.substr(i, d)) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }
        return false;
    }
};