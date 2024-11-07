class Solution {
public:
    int m, n, emp;
    vector<set<int>> se;
    Solution(int m, int n) : m(m), n(n) {
        emp = m * n;
        se.resize(m);
    }
    
    vector<int> flip() {
        int pick = rand() % emp;
        int it = 0, tot = (n - se[0].size());
        while (tot <= pick) {
            it++;
            tot += (n - se[it].size());
        }
        tot -= (n - se[it].size());
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (se[it].count(i)) continue;
            tot++;
            if (tot == (pick + 1)) {
                ret = {it, i};
                break;
            }
        }
        se[it].insert(ret[1]);
        --emp;
        return ret;
    }
    
    void reset() {
        emp = m * n;
        for (int i = 0; i < m; i++) se[i].clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */