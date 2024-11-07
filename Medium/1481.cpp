class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        for (auto c : arr) {
            cnt[c]++;
        }
        vector<int> freq;
        for (auto c : cnt) freq.push_back(c.second);
        sort(freq.begin(), freq.end());
        int sz = freq.size();
        int cur = 0;
        for (int i = 0; i < sz; i++) {
            if (cur + freq[i] > k) {
                return sz - i;
            }
            cur += freq[i];
        }
        return 0;
    }
};