class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ve;
        auto get_freq = [&](const string& s) -> vector<int> {
            vector<int> F(26);
            for (auto c : s) F[c - 'a']++;
            return F;
        };
        for (int i = 0; i < n; i++) {
            if (!ve.empty() && get_freq(words[i]) == get_freq(ve.back())) {
                continue;
            } else {
                ve.push_back(words[i]);
            }
        }
        return ve;
    }
};