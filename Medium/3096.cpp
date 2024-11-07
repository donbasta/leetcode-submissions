class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        int mx = 0;
        for (auto p : possible) {
            if (p == 0) mx--;
            else mx++;
        }
        int cur_score = 0;
        for (int i = 0; i < n - 1; i++) {
            if (possible[i] == 1) {
                cur_score++;
            } else {
                cur_score--;
            }
            if (cur_score * 2 > mx) {
                return (i + 1);
            }
        }
        return -1;
    }
};