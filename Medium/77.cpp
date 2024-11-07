class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        if (k == 0) {
            vector<int> emp;
            ret.push_back(emp);
            return ret;
        }
        if (n == k) {
            vector<int> ret(n);
            iota(ret.begin(), ret.end(), 1);
            return {ret};
        }
        vector<vector<int>> A = combine(n - 1, k);
        vector<vector<int>> B = combine(n - 1, k - 1);
        for (auto e : B) {
            e.push_back(n);
            A.push_back(e);
        }
        return A;
    }
};