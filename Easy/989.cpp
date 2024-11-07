class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> arrayFormK;
        while (k) {
            arrayFormK.push_back(k % 10);
            k /= 10;
        }
        reverse(num.begin(), num.end());
        vector<int> ans;
        int carry = 0;
        for (int i = 0; i < max(num.size(), arrayFormK.size()); i++) {
            int a = (i >= num.size() ? 0 : num[i]);
            int b = (i >= arrayFormK.size() ? 0 : arrayFormK[i]);
            int tot = carry + a + b;
            ans.push_back(tot % 10);
            carry = tot / 10;
        }
        if (carry) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};