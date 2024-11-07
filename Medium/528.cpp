class Solution {
public:
    vector<int> tot;
    int sum;
    Solution(vector<int>& w) {
        int tmp = 0;
        for (auto x : w) {
            tot.push_back(tmp);
            tmp += x;
        }
        sum = tmp;
    }
    
    int pickIndex() {
        return upper_bound(tot.begin(), tot.end(), (rand() % sum)) - tot.begin() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */