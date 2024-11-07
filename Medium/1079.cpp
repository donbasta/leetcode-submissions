class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> cnt;
        for (auto t : tiles) cnt[t]++;
        vector<int> freq;
        for (auto e : cnt) freq.push_back(e.second);
        int ret = 0;
        const function<void()> bt = [&]() {
            for (int i = 0; i < cnt.size(); i++) {
                if (cnt[i] == 0) continue;
                ret++;
                cnt[i]--;
                bt();
                cnt[i]++;
            }
        };
        bt();
        return ret;
    }
};