class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if (num == 0) return true;
        for (int i = 1; i <= num; i++) {
            string s = to_string(i);
            string rs = s;
            reverse(rs.begin(), rs.end());
            int lol = stoi(rs);
            if (lol + i == num) return true;
        }
        return false;
    }
};