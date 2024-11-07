class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        vector<long long> ret;
        int n = nums.size();
        assert (removeQueries.size() == n);

        multiset<long long> segmentSums;
        set<pair<int, int>> intervals;
        vector<long long> pre(n);

        for (int i = 0; i < n; i++) {
            pre[i] = 1LL * nums[i] + (i ? pre[i - 1] : 0);
        }
        
        segmentSums.emplace(-pre[n - 1]);
        intervals.emplace(0, n - 1);
        for (int i = 0; i < n; i++) {
            int buang = removeQueries[i];
            auto ptr = intervals.lower_bound(make_pair(buang + 1, -1));
            assert (ptr != intervals.begin());
            --ptr;
            int le = ptr->first, ri = ptr->second;
            long long sumThisInterval = pre[ri] - (le ? pre[le - 1] : 0);
            intervals.erase(ptr);
            segmentSums.erase(segmentSums.find(-sumThisInterval));
            if (le <= buang - 1) {
                intervals.emplace(le, buang - 1);
                segmentSums.emplace(-(pre[buang - 1] - (le ? pre[le - 1] : 0)));
            }
            if (ri >= buang + 1) {
                intervals.emplace(buang + 1, ri);
                segmentSums.emplace(-(pre[ri] - pre[buang]));
            }
            ret.push_back(-(*(segmentSums.begin())));
        }

        return ret;
    }
};