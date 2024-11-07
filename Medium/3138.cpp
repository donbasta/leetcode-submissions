class Solution {
public:
    int minAnagramLength(string s) {
        vector<int> cnt(26);
        int n = s.length();
        for (auto c : s) cnt[c - 'a']++;

        vector<int> divs;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divs.push_back(i);
                if (i * i != n) divs.push_back(n / i);
            }
        }
        sort(divs.begin(), divs.end());
        for (auto d : divs) {
            vector<int> L(26);
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] % (n / d) != 0) {
                    ok = false;
                    break;
                }
                L[i] = cnt[i] / (n / d);
            }
            if (!ok) continue;
            for (int i = 0; i < n; i += d) {
                vector<int> tmp(26);
                for (int j = i; j < i + d; j++) {
                    tmp[s[j] - 'a']++;
                }
                if (tmp != L) ok = false; 
            }
            if (ok) {
                return d;
            }
        }
        return -1;
    }
};