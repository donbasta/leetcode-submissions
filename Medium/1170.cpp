class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto F = [&](const string& S) -> int {
            char mn = *min_element(S.begin(), S.end());
            int cnt = 0;
            for (auto c : S) cnt += c == mn;
            return cnt;
            // return count(mn, S.begin(), S.end());
        };
        int n = words.size();
        vector<int> f;
        for (auto w : words) f.push_back(F(w));
        sort(f.begin(), f.end());
        vector<int> ret;
        for (auto q : queries) {
            int cari = F(q);
            int fi = upper_bound(f.begin(), f.end(), cari) - f.begin();
            ret.push_back(n - fi);
        }
        return ret;
    }
};