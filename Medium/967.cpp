class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<vector<int>> to(10);
        for (int i = 0; i < 10; i++) {
            if (i - k >= 0) to[i].push_back(i - k);
            if (i + k < 10 && k != 0) to[i].push_back(i + k);
        }
        vector<int> ans;
        for (int i = 1; i <= 9; i++) ans.push_back(i);
        for (int i = 2; i <= n; i++) {
            vector<int> tmp;
            for (auto x : ans) {
                int last = x % 10;
                for (auto c : to[last]) {
                    tmp.push_back(x * 10 + c);
                }
            }
            ans.swap(tmp);
        }
        return ans;
    }
};