class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string t = to_string(n);
        int len = t.length();
        string ret;
        for (int i = 0; i < len; i++) {
            if (i == len - 1) {
                ret.push_back(t[i]);
            } else {
                int check = i;
                while (check < len && t[check] == t[i]) check++;
                if (check == len || (t[check] > t[i])) {
                    ret.push_back(t[i]);
                } else {
                    ret.push_back(t[i] - 1);
                    for (int j = i + 1; j < len; j++) ret.push_back('9');
                    break;
                }
            }
        }
        return stoi(ret);
    }
};