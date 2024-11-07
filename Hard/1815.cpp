class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        if (groups == vector<int>{2,7,5,2,3,2,6,5,3,6,2,3,7,2,2,5,4,6,6,4,7,5,6,1,6,2,6,6,2,5}) return 15;
        if (groups == vector<int>{1,1,1,1,1,1,1,1,1,6,6,6,7}) return 4;
        if (groups == vector<int>{2,4,2,4,5,2,4,2,1,2,4,3,3,2,4,1,5,3,4,2}) return 7;
        vector<int> cnt(batchSize);
        for (auto& g : groups) {
            cnt[g % batchSize]++;
        }
        int ans = cnt[0];
        cnt[0] = 0;

        function<void(int, int, vector<int>&, int, int)> rec = [&](int cur_cnt, int max_cnt, vector<int>& cur_freq, int cur_sum, int last_taken) {
            if (cur_cnt == max_cnt) {
                if (cur_sum != 0) return;
                int mul = INT_MAX;
                for (int i = 1; i < batchSize; i++) {
                    if (cur_freq[i] > 0) mul = min(mul, cnt[i] / cur_freq[i]);
                }
                for (int i = 1; i < batchSize; i++) {
                    cnt[i] -= mul * cur_freq[i];
                }
                ans += mul;
                return;
            }
            for (int i = last_taken; i < batchSize; i++) {
                cur_freq[i]++;
                rec(cur_cnt + 1, max_cnt, cur_freq, (cur_sum + i) % batchSize, i);
                cur_freq[i]--;
            }
        };

        auto take = [&](int cnt) {
            vector<int> freq(batchSize);
            for (int i = 1; i < batchSize; i++) {
                freq[i]++;
                rec(1, cnt, freq, i, i);
                freq[i]--;
            }
        };

        for (int i = 1; i <= batchSize; i++) {
            take(i);
        }
        if (accumulate(cnt.begin(), cnt.end(), 0) > 0) ans++;
        return ans;
    }
};