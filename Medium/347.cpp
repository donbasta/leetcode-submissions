class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (auto num : nums) {
            freq[num]++;
        }
        vector<pair<int, int>> tmp;
        for (auto f : freq) {
            tmp.emplace_back(f.second, f.first);
        }
        sort(tmp.begin(), tmp.end(), greater<>());
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.emplace_back(tmp[i].second);
        }
        return res;
    }
};