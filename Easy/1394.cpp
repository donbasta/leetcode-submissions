class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mp;
        for (auto e : arr) mp[e]++;
        int ans = -1;
        for (auto e : mp) {
            if (e.first == e.second) ans = e.first;
        }
        return ans;
    }
};