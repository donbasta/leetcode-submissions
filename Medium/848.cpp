class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        const int A = 26;
        for (int i = n - 2; i >= 0; i--) {
            shifts[i] = (shifts[i] + shifts[i + 1]) % A;
        }
        for (int i = 0; i < n; i++) {
            int cur = s[i] - 'a';
            cur = (cur + shifts[i]) % A;
            s[i] = (cur + 'a');
        }
        return s;
    }
};