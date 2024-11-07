class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        set<string> se;
        string tmp;
        for (auto c : s) {
            tmp += c;
            se.insert(tmp);
        }
        int ans = 0;
        for (auto w : words) {
            ans += se.count(w);
        }
        return ans;
    }
};