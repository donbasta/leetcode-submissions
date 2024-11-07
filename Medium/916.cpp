class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> cnt2(26);
        for (auto w2 : words2) {
            vector<int> tmp(26);
            for (auto c : w2) {
                tmp[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                cnt2[i] = max(cnt2[i], tmp[i]);
            }
        }
        vector<string> ans;
        for (auto w1 : words1) {
            vector<int> tmp(26);
            for (auto c : w1) {
                tmp[c - 'a']++;
            }
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                ok &= (tmp[i] >= cnt2[i]);
            }
            if (ok) {
                ans.push_back(w1);
            }
        }
        return ans;
    }
};