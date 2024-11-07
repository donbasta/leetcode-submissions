class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<int> cnt1(1001), cnt2(1001);
        for (auto e : nums1) cnt1[e]++;
        for (auto e : nums2) cnt2[e]++;
        for (int i = 0; i <= 1000; i++) {
            int rep = min(cnt1[i], cnt2[i]);
            for (int j = 0; j < rep; j++) ans.push_back(i);
        }
        return ans;
    }
};