class Solution {
public:
    string decodeCiphertext(string enc, int rows) {
        int n = enc.length();
        int col = n / rows;
        string tmp;
        for (int i = 0; i < col; i++) {
            int cur = i;
            while (cur < n) {
                tmp.push_back(enc[cur]);
                cur += (col + 1);
            }
        }
        while (!tmp.empty() && tmp.back() == ' ') tmp.pop_back();
        return tmp;
    }

};