class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> ve(numRows);
        int n = s.size();
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < n; j += 2 * (numRows - 1)) {
                ve[i] += s[j];
                if (i != 0 && i != numRows - 1) {
                    int nx = j + 2 * (numRows - 1 - i);
                    if (nx < n) ve[i] += s[nx]; 
                }
            }
        }
        string ret;
        for (int i = 0; i < numRows; i++) {
            ret += ve[i];
        }
        return ret;
    }
};