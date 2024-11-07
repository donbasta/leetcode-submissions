class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.length();
        vector<int> ve(m);
        map<char, pair<int, int>> move = {
            {'L', make_pair(0, -1)},
            {'R', make_pair(0, 1)},
            {'D', make_pair(1, 0)},
            {'U', make_pair(-1, 0)},
        };
        for (int i = 0; i < m; i++) {
            int ci = startPos[0], cj = startPos[1];
            int steps = i;
            while (steps < m && ci >= 0 && ci < n && cj >= 0 && cj < n) {
                ci += move[s[steps]].first, cj += move[s[steps]].second;
                if (ci >= 0 && ci < n && cj >= 0 && cj < n) steps++;
            }
            ve[i] = steps - i;
        }
        return ve;
    }
};