class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        vector<pair<char, char>> ve;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                ve.emplace_back(s1[i], s2[i]);
            }
        }
        if (ve.size() != 0 && ve.size() != 2) return false;
        if (ve.size() == 0) return true;
        assert (ve.size() == 2);
        swap(ve[0].first, ve[0].second);
        // cout << ve[0].first << ' ' << ve[0].second << ' ' << ve[1].first << ' ' << ve[1].second << '\n';
        return ve[0] == ve[1];
    }
};