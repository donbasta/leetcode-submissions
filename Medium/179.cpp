class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> T;
        for (auto e : nums) {
            T.emplace_back(to_string(e));
        }
        sort(T.begin(), T.end(), [&](const string& a, const string& b) -> bool {
            int idx = 0;
            int as = a.size(), bs = b.size();
            int tot = as / __gcd(as, bs) * bs;
            while (idx < tot) {
                if (a[idx % a.size()] == b[idx % b.size()]) {
                    idx++;
                } else {
                    return a[idx % a.size()] > b[idx % b.size()];
                }
            }
            return a[idx % a.size()] > b[idx % b.size()];
        });
        string ret;
        int idx = 0;
        while (idx < (int)T.size() && T[idx] == "0") idx++;
        for (int i = idx; i < (int)T.size(); i++) ret += T[i];
        if (ret == "") return "0";
        return ret;
    }
};