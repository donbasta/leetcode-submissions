class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.length();
        int ans = 0;
        for (int i = 0; i <= n - k; i++) {
            int cek = stoi(s.substr(i, k));
            if (cek == 0) continue;
            ans += num % cek == 0;
        }
        return ans;
    }
};