class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int win = 0;
        int cur = -1;
        int pos = -1;
        int idx = 0;
        deque<pair<int, int>> Q;
        int n = skills.size();
        for (auto s : skills) Q.push_back(make_pair(s, idx++));
        while (true) {
            pair<int, int> a = Q.front();
            Q.pop_front();
            pair<int, int> b = Q.front();
            Q.pop_front();
            int winner = max(a.first, b.first);
            int win_pos = (a.first > b.first) ? a.second : b.second;
            if (a.first > b.first) {
                Q.push_front(a);
                Q.push_back(b);
            } else {
                Q.push_front(b);
                Q.push_back(a);
            }
            if (winner == cur) win++;
            else {
                win = 1, cur = winner, pos = win_pos;
            }
            if (win >= min(n - 1, k)) {
                return pos;
            }
        }
        assert(false);
        return -1;
    }
};