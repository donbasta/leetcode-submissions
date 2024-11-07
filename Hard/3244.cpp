class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int rem = 0;
        vector<int> ret;
        set<pair<int, int>> se;
        for (auto q : queries) {
            auto ptr = se.lower_bound(make_pair(q[0] + 1, -1));
            if (ptr != se.begin() && (--ptr)->second >= q[1]) {
                ret.push_back(n - 1 - rem);
                continue;
            }

            ptr = se.lower_bound(make_pair(q[0], 0));
            vector<pair<int, int>> buf;
            while (ptr != se.end() && ptr->second <= q[1]) {
                rem -= (ptr->second - ptr->first) - 1;
                buf.push_back(*ptr);
                ++ptr;
            }
            for (auto b : buf) se.erase(b);
            se.emplace(q[0], q[1]);
            rem += q[1] - q[0] - 1;
            ret.push_back(n - 1 - rem);
        }
        return ret;
    }
};