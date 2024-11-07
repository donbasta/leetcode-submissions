class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        vector<int> ep;
        for (auto itv : intervals) {
            ep.push_back(itv[0]), ep.push_back(itv[1]);
        }
        sort(ep.begin(), ep.end());
        ep.resize(unique(ep.begin(), ep.end()) - ep.begin());
        int sz = ep.size();
        bool take[sz];
        memset(take, false, sizeof(take));
        sort(intervals.begin(), intervals.end(), [&](vector<int> A, vector<int> B) -> bool {
            if (A[1] == B[1]) {
                return A[0] < B[0];
            }
            return A[1] < B[1];
        });
        int itr = 0;
        for (auto itv : intervals) {
            while (ep[itr] < itv[1]) itr++;
            int tmp = itr;
            int cnt = 0;
            while (tmp >= 0 && ep[tmp] >= itv[0]) {
                cnt += take[tmp];
                tmp--;
            }
            tmp = itr;
            while (tmp >= 0 && cnt < 2 && ep[tmp] >= itv[0]) {
                if (take[tmp]) {
                    tmp--;
                    continue;
                }
                take[tmp] = true;
                cnt++;
                tmp--;
            }
        }
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            ans += take[i];
        }
        return ans;
    }
};