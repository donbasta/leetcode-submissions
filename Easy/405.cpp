class Solution {
public:
    string toHex(int num) {
        string ans;
        for (int i = 0; i < 8; i++) {
            int sm = (num >> (4 * i)) & 15;
            if (sm < 10) {
                ans.push_back((char)(sm + '0'));
            } else {
                ans.push_back((char)(sm - 10 + 'a'));
            }
        }
        while (!ans.empty() && ans.back() == '0') ans.pop_back();
        if (ans.empty()) ans.push_back('0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};