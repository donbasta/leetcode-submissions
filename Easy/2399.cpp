class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> pos(26, -1);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int cur = s[i] - 'a';
            if (pos[cur] == -1) pos[cur] = i;
            else {
                if (i - 1 - pos[cur] != distance[cur]) return false;
            }
        }
        return true;
    }
};