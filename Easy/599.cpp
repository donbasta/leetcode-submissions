class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> m1, m2;
        for (int i = (int)list1.size() - 1; i >= 0; i--) {
            m1[list1[i]] = i;
        }
        for (int i = (int)list2.size() - 1; i >= 0; i--) {
            m2[list2[i]] = i;
        }
        vector<string> ans;
        int mn = INT_MAX;
        for (auto e : m1) {
            if (!m2.count(e.first)) continue;
            mn = min(mn, e.second + m2[e.first]);
        }
        if (mn == INT_MAX) return ans;
        for (auto e : m1) {
            if (!m2.count(e.first)) continue;
            if (e.second + m2[e.first] == mn) {
                ans.push_back(e.first);
            }
        }
        return ans;
    }
};