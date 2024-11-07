class Solution {
public:
    string losingPlayer(int x, int y) {
        int turn = 0;
        while (true) {
            if ((x < 1) || (y < 4)) {
                if (turn == 0) return "Bob";
                else return "Alice";
            }
            turn = 1 - turn;
            x--;
            y -= 4;
        }
        return "";
    }
};