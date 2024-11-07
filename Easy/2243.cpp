class Solution {
public:
    string digitSum(string s, int k) {
        
        while (s.length() > k) {
            string cur;
            int n = s.length();
            for (int i = 0; i < n; i += k) {
                int tmp = 0;
                for (int j = i; j < min(n, i + k); j++) {
                    tmp += s[j] - '0';
                }
                cur += to_string(tmp);
            }
            s = cur;
        }
        return s;
    }
};