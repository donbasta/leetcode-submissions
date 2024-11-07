class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>> ve(26, make_pair(-1, -1));
        for (int i = 0; i < s.length(); i++) {
            if (ve[s[i] - 'a'].first == -1) {
                ve[s[i] - 'a'].first = i;
            }
            ve[s[i] - 'a'].second = i;
        }
        vector<pair<int, int>> ve2;
        for (auto e : ve) {
            if (e != make_pair(-1, -1)) ve2.push_back(e);
        }
        sort(ve2.begin(), ve2.end());
        int l = ve2[0].first, r = ve2[0].second;
        vector<int> parts;
        for (int i = 1; i < ve2.size(); i++) {
            if (ve2[i].first > r) {
                parts.emplace_back(r - l + 1);
                l = ve2[i].first;
                r = ve2[i].second;
            } else {
                r = max(r, ve2[i].second);
            }
        }
        parts.emplace_back(r - l + 1);
        return parts;
    }
};