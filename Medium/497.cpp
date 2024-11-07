class Solution {
public:
    vector<int> tot;
    int cnt;
    vector<vector<int>> _rects;

    Solution(vector<vector<int>>& rects) {
        _rects = rects;
        tot.push_back(0);
        int tmp = 0;
        for (auto e : rects) {
            int count = (e[2] - e[0] + 1) * (e[3] - e[1] + 1);
            tmp += count;
            tot.push_back(tmp);
        }
        cnt = tmp;
    }
    
    vector<int> pick() {
        int x = rand() % cnt;
        int idx = upper_bound(tot.begin(), tot.end(), x) - tot.begin();
        --idx;
        int order = x - tot[idx];
        int num_col = _rects[idx][2] - _rects[idx][0] + 1;
        int a = order % num_col;
        int b = order / num_col;
        return {_rects[idx][0] + a, _rects[idx][1] + b};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */