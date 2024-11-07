class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), [&](const vector<int>& a, const vector<int>& b) -> bool {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });
        vector<vector<int>> ret;

        int n = p.size();
        for (int i = 0; i < n; i++) {
            int pos = 0;
            int cnt = 0;
            while (pos < i) {
                if (ret[pos][0] >= p[i][0]) cnt++;
                if (cnt > p[i][1]) {
                    break;
                }
                pos++;
            }
            ret.push_back(p[i]);
            for (int j = i - 1; j >= pos; j--) {
                swap(ret[j], ret[j + 1]);
            }
        }
        return ret;
    }
};