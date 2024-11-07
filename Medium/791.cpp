class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.size();
        vector<int> pos(26);
        for (int i = 0; i < n; i++) {
            pos[order[i] - 'a'] = i;
        }
        sort(s.begin(), s.end(), [&](char a, char b) -> bool {
            return pos[a - 'a'] < pos[b - 'a'];
        });
        return s;
    }
};