class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        vector<int> ret(2);
        {
            int a = stones.back() - stones[1] - (n - 2);
            int b = stones[n - 2] - stones[0] - (n - 2);
            ret[1] = max(a, b);
        }
        {
            int pt = 0;
            ret[0] = INT_MAX;
            for (int i = 0; i < n; i++) {
                while (pt < n && stones[pt] <= stones[i] + n - 1) pt++;
                if (stones[i] + n - 1 > stones.back()) break;
                // cout << i << ' ' << pt << '\n';
                if (pt - i == n - 1 && stones[pt - 1] == stones[i] + n - 2) continue;
                ret[0] = min(ret[0], n - (pt - i));
            }
        }
        return ret;
    }
};