class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        int idx = -1;
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (number[i] != digit) continue;
            last = i;
            if (i == n - 1 || number[i] < number[i + 1]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) idx = last;
        // assert (idx != -1);
        string ret;
        for (int i = 0; i < n; i++) {
            if (i == idx) continue;
            ret.push_back(number[i]);
        }
        return ret;
    }
};