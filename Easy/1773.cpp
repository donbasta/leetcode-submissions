class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        map<string, int> mp;
        mp["type"] = 0, mp["color"] = 1, mp["name"] = 2;
        int ans = 0;
        for (auto e : items) {
            ans += e[mp[ruleKey]] == ruleValue;
        }
        return ans;
    }
};