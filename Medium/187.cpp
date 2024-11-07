class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();

        vector<string> ans;
        if (n < 10) return ans;
        unordered_map<string, int> cnt;
        for (int i = 0; i <= n - 10; i++) {
            cnt[s.substr(i, 10)]++;
        }
        for (auto e : cnt) {
            if (e.second > 1) ans.push_back(e.first);
        }
        return ans;
    }
};