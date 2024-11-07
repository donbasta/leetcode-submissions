class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto w : words) {
            cnt[w]++;
        }
        vector<string> ret;
        vector<pair<int, string>> tmp;
        for (auto e : cnt) {
            tmp.push_back(make_pair(e.second, e.first));
        }
        sort(tmp.begin(), tmp.end(), [&](pair<int, string> a, pair<int, string> b) -> bool {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
        for (int i = 0; i < k; i++) {
            ret.push_back(tmp[i].second);
        }
        return ret;
    }
};