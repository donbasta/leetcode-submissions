class Solution {
public:
    string alphabetBoardPath(string target) {
        int x = 0, y = 0;
        string ret;
        int now = 0;
        for (auto c : target) {
            int cur = c - 'a';
            int tx = cur / 5, ty = cur % 5;
            if (c == 'z') {
                for (int i = 0; i < y; i++) ret.push_back('L');
                for (int i = 0; i < (5 - x); i++) ret.push_back('D');
            } else {
                char hori = 'R', ver = 'U';
                if (ty < y) hori = 'L';
                if (tx > x) ver = 'D';
                for (int i = 0; i < abs(tx - x); i++) ret.push_back(ver);
                for (int i = 0; i < abs(ty - y); i++) ret.push_back(hori);
            }
            ret.push_back('!');
            x = tx, y = ty;
        }
        return ret;
    }
};