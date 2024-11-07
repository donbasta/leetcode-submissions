class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int L = nums[0].length();
        vector<int> ans;
        for (auto q : queries) {
            int k = q[0], len = q[1];
            vector<pair<string, int>> ve;
            int idx = 0;
            for (auto n : nums) {
                string tmp = n.substr(L - len, len);
                ve.emplace_back(tmp, idx++);
            }
            sort(ve.begin(), ve.end());
            ans.push_back(ve[k - 1].second);
        }
        return ans;
    }
};