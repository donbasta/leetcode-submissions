class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int x = rounds[0], y = rounds.back();
        vector<int> ret;
        for (int i = x; i != y; i = i % n + 1) {
            ret.push_back(i);
        }
        ret.push_back(y);
        sort(ret.begin(), ret.end());
        return ret;
    }
};