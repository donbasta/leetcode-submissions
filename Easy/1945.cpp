class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        string tmp;
        for (auto c : s) {
            tmp += to_string((c - 'a' + 1));
        }
        for (int i = 0; i < k; i++) {
            int sum = 0;
            for (auto c : tmp) {
                sum += (c - '0');
            }
            tmp = to_string(sum);
        }
        return stoi(tmp);
    }
};