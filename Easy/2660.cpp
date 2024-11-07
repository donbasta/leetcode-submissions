class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = player1.size();
        int a1 = 0, a2 = 0;
        for (int i = 0; i < n; i++) {
            int score = player1[i];
            if ((i >= 1 && player1[i - 1] == 10) || (i >= 2 && (player1[i - 1] == 10 || player1[i - 2] == 10))) {
                score *= 2;
            }
            a1 += score;
        }
        for (int i = 0; i < n; i++) {
            int score = player2[i];
            if ((i >= 1 && player2[i - 1] == 10) || (i >= 2 && (player2[i - 1] == 10 || player2[i - 2] == 10))) {
                score *= 2;
            }
            a2 += score;
        }
        if (a1 > a2) return 1;
        else if (a2 > a1) return 2;
        return 0;
    }
};