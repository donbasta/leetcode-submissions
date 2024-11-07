class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int cur = 2;
        int now = 1;
        while (s.length() < n) {
            for (int i = 0; i < (s[cur] - '0'); i++) {
                s.push_back((char)(now + '0'));
            }
            cur++;
            now = 3 - now;
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};