class Solution {
public:
    string addBinary(string a, string b) {
        string na = a, nb = b;
        reverse(na.begin(), na.end());
        reverse(nb.begin(), nb.end());
        int carry = 0;
        string ans;
        for (int i = 0; i < max(na.length(), nb.length()); i++) {
            int ca = i >= na.length() ? 0 : (na[i] - '0'); 
            int cb = i >= nb.length() ? 0 : (nb[i] - '0');
            int sum = carry + ca + cb;
            carry = sum / 2;
            ans.push_back((char)((sum & 1) + '0'));
        }
        if (carry >= 1) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};