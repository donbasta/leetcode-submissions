class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        
        int ret = INT_MAX;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0; i < n + 2; i++) {
            for (int j = i + 1; j < n + 2; j++) {
                vector<int> tmp;
                for (int k = 0; k < n + 2; k++) {
                    if (k == i || k == j) continue;
                    tmp.push_back(nums1[k]);
                }
                int sel = nums2[0] - tmp[0];
                bool ok = true;
                for (int k = 0; k < n; k++) {
                    if (nums2[k] - tmp[k] != sel) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ret = min(ret, sel);
                }
            }
        }
        assert (ret != INT_MAX);
        return ret;
    }
};