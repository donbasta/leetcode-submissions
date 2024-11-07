class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> se;
        for (int i = 0; i < (1 << n); i++) {
            vector<int> tmp;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) tmp.push_back(nums[j]);
            }
            if (tmp.size() < 2) continue;
            bool ok = true;
            for (int j = 1; j < tmp.size(); j++) {
                if (tmp[j] < tmp[j - 1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) se.insert(tmp);
        }
        return vector<vector<int>>(se.begin(), se.end());
    }
};