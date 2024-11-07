class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.length(), np = p.length();
        vector<int> ans;
        if (np > ns) return ans;
        vector<int> cntP(26);
        for (auto c : p) cntP[c - 'a']++;
        vector<int> cntS(26);
        for (int i = 0; i < np - 1; i++) {
            cntS[s[i] - 'a']++;
        }
        for (int i = np - 1; i < ns; i++) {
            cntS[s[i] - 'a']++;
            if (cntS == cntP) ans.push_back(i - np + 1);
            cntS[s[i - np + 1] - 'a']--;
        }
        return ans;
    }
};