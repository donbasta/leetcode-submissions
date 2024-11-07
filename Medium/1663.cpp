class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, '.');
        int rem = k;
        for (int i = 0; i < n; i++) {
            // (n - 1 - i) <= rem - x <= 26 * (n - 1 - i)
            // x >= max(1, rem - 26 * (n - 1 - i))

            int val = max(1, rem - 26 * (n - 1 - i));
            s[i] = (char) (val - 1 + 'a');
            rem -= val;
        }
        return s;
    }
};