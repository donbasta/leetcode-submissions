class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int cur = 0;
        for (auto c : commands) {
            if (c == "RIGHT") cur++;
            else if (c == "LEFT") cur--;
            else if (c == "UP") cur -= n;
            else cur += n;
        }
        return cur;
    }
};