class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp1, mp2;
        for (auto e : arr1) {
            while (e > 0) {
                mp1[e]++;
                e /= 10;
            }
        }
        for (auto e : arr2) {
            while (e > 0) {
                mp2[e]++;
                e /= 10;
            } 
        }
        int ans = 0;
        for (auto e : mp1) {
            if (mp2.count(e.first)) {
                ans = max(ans, (int)to_string(e.first).length());
            }
        }
        return ans;
    }
};