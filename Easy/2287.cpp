class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> c1(26), c2(26);
        for (auto c : target) c1[c - 'a']++;
        for (auto c : s) c2[c - 'a']++;
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (c1[i] == 0) continue;
            ans = min(ans, c2[i] / c1[i]);
        }
        return ans;
    }
};