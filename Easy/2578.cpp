class Solution {
public:
    int splitNum(int num) {
        string lmao = to_string(num);
        sort(lmao.begin(), lmao.end());
        reverse(lmao.begin(), lmao.end());
        int n = lmao.length();
        int pw = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int dig = lmao[i] - '0';
            ans += dig * pw;
            if (i & 1) pw *= 10;
        }
        return ans;
    }
};