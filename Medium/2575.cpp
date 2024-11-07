class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ve;
        int cur = 0;
        for (auto c : word) {
            int dig = (c - '0');
            cur = (1ll * cur * 10 + dig) % m;
            ve.push_back((cur % m == 0));
        }
        return ve;
    }
};