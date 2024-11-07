class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        map<string, int> cnt;
        int n = word.size();
        for (int i = 0; i < n; i += k) {
            cnt[word.substr(i, k)]++;
        }
        int mx = 0;
        for (auto x : cnt) {
            mx = max(mx, x.second);
        }
        return (n / k) - mx;
    }
};