class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> freq(n, vector<int>(26));
        for (int i = 0; i < n; i++) {
            for (auto c : words[i]) freq[i][c - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                bool ok = true;
                for (int k = 0; k < 26; k++) {
                    if (freq[i][k] > 0 && freq[j][k] > 0) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    int ni = words[i].length(), nj = words[j].length();
                    ans = max(ans, ni * nj);
                }
            }
        }
        return ans;
    }
};