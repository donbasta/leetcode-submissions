class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans;
        for (int i = 0; i < max(num1.length(), num2.length()); i++) {
            int a = (i < num1.length() ? (num1[i] - '0') : 0);
            int b = (i < num2.length() ? (num2[i] - '0') : 0);
            int now = carry + a + b;
            int nowDig = now % 10;
            carry = now / 10;
            ans.push_back((char)(nowDig + '0'));
        }
        if (carry > 0) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};