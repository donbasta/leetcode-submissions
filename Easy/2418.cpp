class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> ve;
        for (int i = 0; i < n; i++) {
            ve.emplace_back(heights[i], names[i]);
        }
        sort(ve.rbegin(), ve.rend());
        vector<string> ret;
        for (int i = 0; i < n; i++) {
            ret.push_back(ve[i].second);
        }
        return ret;
    }
};