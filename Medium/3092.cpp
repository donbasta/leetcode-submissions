using ll = long long;

class Solution {
public:
    vector<ll> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<ll> ret;
        multiset<ll> ms;
        map<int, ll> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (ms.count(mp[nums[i]])) {
                ms.erase(ms.find(mp[nums[i]]));
            }
            mp[nums[i]] += freq[i];
            if (mp[nums[i]] != 0) {
                ms.insert(mp[nums[i]]);
            }
            if (ms.empty()) ret.push_back(0);
            else ret.push_back(*ms.rbegin());
        }
        return ret;

    }
};