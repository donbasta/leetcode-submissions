class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<pair<int, int>> se;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            se.emplace(nums[i], i);
        }
        long long score = 0;
        while (!se.empty()) {
            auto sm = *se.begin();
            score += sm.first;
            int id = sm.second;
            se.erase(sm);
            if (id > 0) se.erase(make_pair(nums[id - 1], id - 1));
            if (id < n - 1) se.erase(make_pair(nums[id + 1], id + 1));
        }
        return score;
    }
};