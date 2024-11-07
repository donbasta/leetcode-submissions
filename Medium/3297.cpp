class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> c2(26), cur(26);
        for (auto c : word2) c2[c - 'a']++;
        int n = word1.size();
        int r = -1;
        using ll = long long;
        ll ans = 0;

        auto enough = [&]() -> bool {
            for (int i = 0; i < 26; i++) {
                if (cur[i] < c2[i]) return false;
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
            while (!enough()) {
                r++;
                if (r == n) break;
                cur[word1[r] - 'a']++;
            }
            // cout << i << ' ' << r << '\n';
            if (r == n) break;
            ans += (n - r);
            cur[word1[i] - 'a']--;
        } 
        return ans;
    }
};