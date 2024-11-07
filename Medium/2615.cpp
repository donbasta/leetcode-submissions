class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> ump;
        int n = nums.size();
        vector<long long> ar(n);
        for (int i = 0; i < n; i++) {
            ump[nums[i]].push_back(i);
        }
        for (auto e : ump) {
            vector<int> ve = e.second;
            int m = ve.size();
            long long cur = 0;
            for (int i = 1; i < m; i++) cur += ve[i];
            cur -= 1ll * (m - 1) * ve[0];
            ar[ve[0]] = cur;
            for (int i = 1; i < m; i++) {
                // from ar(m - 1) + ... + ar
                // to ar(m - 1) + ar(m - 2) + ... + ar(i + 1) - (m - 1 - i) * ar(i) + (i * ar(i) - ar(i - 1) - ... - ar(0));

                // ar(m - 1) + .... + ar(i + 1) - ar(i - 1) - ar(i - 2) - ... - ar(0) + (2i + 1 - m) * ar(i)
                // ar(m - 1) + ... + ar(i + 1) + ar(i) - ar(i - 2) - ... - ar(0) + (2i - 1 - m) * ar(i - 1)
                
                cur -= 1ll * (2 * i - m) * ve[i - 1];
                cur += 1ll * (2 * i - m) * ve[i];
                ar[ve[i]] = cur;
            }
        }
        return ar;
    }
};