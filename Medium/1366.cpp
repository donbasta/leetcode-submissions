class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string participants = votes[0];
        vector<vector<int>> score(26, vector<int>(participants.size()));
        for (auto vote : votes) {
            for (int i = 0; i < vote.size(); i++) {
                score[vote[i] - 'A'][i]++;
            }
        }
        sort(participants.begin(), participants.end(), [&](char a, char b) -> bool {
            if (score[a - 'A'] == score[b - 'A']) return a < b;
            return score[a - 'A'] > score[b - 'A'];
        });
        return participants; 
    }
};