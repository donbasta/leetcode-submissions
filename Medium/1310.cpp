class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pre(n);
        for (int i = 0; i < n; i++) {
            pre[i] = (arr[i] ^ (i ? pre[i - 1] : 0));
        }
        vector<int> ret;
        for (auto q : queries) {
            ret.push_back(pre[q[1]] ^ (q[0] ? pre[q[0] - 1] : 0));
        }
        return ret;
    }
};