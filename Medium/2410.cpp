class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int m = players.size(), n = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int ptr = 0, ret = 0;
        for (int i = 0; i < n; i++) {
            if (ptr == m || players[ptr] > trainers[i]) continue;
            else {
                ptr++;
                ret++;
            }
        }
        return ret;
    }
};