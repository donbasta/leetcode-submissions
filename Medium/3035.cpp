class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> cnt(26), lens;
        for (auto w : words) {
            lens.push_back(w.length());
            for (auto c : w) {
                cnt[c - 'a']++;
            }
        }
        sort(lens.begin(), lens.end());
        int tot = 0;
        for (auto c : cnt) tot += c / 2;
        int res = 0;
        for (auto l : lens) {
            int nn = l / 2;
            if (tot >= nn) {
                tot -= nn;
                res++;
            } else {
                break;
            }
        }
        return res;
    }
};