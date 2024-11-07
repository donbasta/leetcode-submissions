class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k);
        map<int, set<int>> hehe;
        for (auto l : logs) {
            hehe[l[0]].insert(l[1]);
        }
        for (auto e : hehe) {
            ans[e.second.size() - 1]++;
        }
        return ans;
    }
};