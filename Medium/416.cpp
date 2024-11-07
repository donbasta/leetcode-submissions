class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot = 0;
        for (auto e : nums) tot += e;
        if (tot & 1) return false;
        unordered_map<int, bool> ok;
        ok[0] = true;
        for (auto e : nums) {
            vector<int> tmp;
            for (auto f : ok) {
                tmp.push_back(f.first + e);
            }
            for (auto f : tmp) {
                ok[f] = true;
            }
        }
        return (ok.find(tot / 2) != ok.end());
    }
};