class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ret;
        int n = nums.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto q : queries) {
            if (!mp.count(x)) ret.push_back(-1);
            else if ((int)mp[x].size() < q) ret.push_back(-1);
            else {
                ret.push_back(mp[x][q - 1]);
            }
        }
        return ret;
    }
};