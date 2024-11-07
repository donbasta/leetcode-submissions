class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for (auto& d : dominoes) {
            if (d[0] > d[1]) swap(d[0], d[1]);
        }
        map<vector<int>, int> mp;
        int ans = 0;
        for (auto d : dominoes) {
            ans += mp[d];
            mp[d]++;
        } 
        return ans;
    }
};