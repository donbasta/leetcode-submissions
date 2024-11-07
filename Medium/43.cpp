class Solution {
public:
    string multiply(string num1, string num2) {
        const function<string(string, string)> add = [&](string a, string b) -> string {
            string ret;
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            int na = a.length(), nb = b.length();
            int carry = 0;
            for (int i = 0; i < max(na, nb); i++) {
                int dig_a = (i < na ? (a[i] - '0') : 0);
                int dig_b = (i < nb ? (b[i] - '0') : 0);
                int tot = carry + dig_a + dig_b;
                int new_dig = tot % 10;
                carry = tot / 10;
                ret.push_back((char)(new_dig + '0'));
            }
            if (carry > 0) ret.push_back('1');
            while (ret.back() == '0' && ret.size() > 1) {
                ret.pop_back();
            }
            reverse(ret.begin(), ret.end());
            return ret;
        };

        vector<string> multiples(10);
        multiples[0] = "0";
        multiples[1] = num1;
        for (int i = 2; i <= 9; i++) {
            multiples[i] = add(multiples[i - 1], num1);
        }

        int n = num2.length();
        vector<string> adds;
        for (int i = n - 1; i >= 0; i--) {
            string tmp = multiples[num2[i] - '0'];
            for (int j = 1; j <= n - 1 - i; j++) tmp.push_back('0');
            adds.push_back(tmp);
        }

        string ans = adds[0];
        for (int i = 1; i < adds.size(); i++) {
            ans = add(ans, adds[i]);
        }
        return ans;
    }
};