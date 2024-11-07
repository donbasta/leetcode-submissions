class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> len;
        for (auto e : arr) {
            len[e] = len[e - difference] + 1;
        }
        int ans = 1;
        for (auto e : len) {
            ans = max(ans, e.second);
        }
        return ans;
    }
};