class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        const function<bool(char)> isVowel = [&](char c) -> bool {
            return c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o';
        };
        vector<int> pre(n);
        for (int i = 0; i < n; i++) {
            pre[i] = (i ? pre[i - 1] : 0);
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                pre[i]++;
            }
        }
        vector<int> ans;
        for (auto e : queries) {
            int l = e[0], r = e[1];
            ans.push_back(pre[r] - (l ? pre[l - 1] : 0));
        }
        return ans;
    }
};