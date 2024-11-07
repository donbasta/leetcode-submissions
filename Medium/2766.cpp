class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int, int> count;
        for (auto e : nums) count[e]++;
        int n = moveFrom.size();
        for (int i = 0; i < n; i++) {
            if (moveFrom[i] == moveTo[i]) continue;
            int x = count[moveFrom[i]];
            count[moveTo[i]] += x;
            count[moveFrom[i]] = 0;
        }
        vector<int> ve;
        for (auto e : count) {
            if (e.second > 0) {
                ve.push_back(e.first);
            }
        }
        sort(ve.begin(), ve.end());
        return ve;
    }
};