class Solution {
public:
    int candy(vector<int>& ratings) {
        int cur_peak_idx = 0;
        int tot = 1;
        int last = 1;
        int n = ratings.size();
        int stat = -1; // state of sequence; -1 nothing, 0 is currently decreasing, 1 is currently increasing
        for (int i = 1; i < n; i++) {
            if (ratings[i] == ratings[i - 1]) {
                if (stat == 0) {
                    tot -= ((last - 1) * (i - 1 - cur_peak_idx));
                }
                cur_peak_idx = i;
                tot += 1;
                last = 1;
                stat = -1;
            } else if (ratings[i] > ratings[i - 1]) {
                if (stat == 0) {
                    tot -= ((last - 1) * (i - 1 - cur_peak_idx));
                    last = 1;
                }
                cur_peak_idx = i;
                tot += (last + 1);
                last++;
                stat = 1;
            } else if (ratings[i] < ratings[i - 1]) {
                if (last == 1) {
                    tot += (i - cur_peak_idx + 1);
                } else {
                    tot += (last - 1);
                    last--;
                }
                stat = 0;
            }
        }
        if (stat == 0) {
            tot -= ((last - 1) * (n - 1 - cur_peak_idx));
        }
        return tot;
    }
};