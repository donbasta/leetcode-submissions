class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int t1 = accumulate(nums1.begin(), nums1.end(), 0);
        int t2 = accumulate(nums2.begin(), nums2.end(), 0);
        
        if (t1 > t2) {
            swap(t1, t2);
            nums1.swap(nums2);
        }

        vector<int> ve;
        int rem = t2 - t1;
        for (auto e : nums1) ve.push_back(6 - e);
        for (auto e : nums2) ve.push_back(e - 1);
        sort(ve.begin(), ve.end(), greater<>());
        int ptr = 0;
        while (ptr < (int)ve.size() && rem > 0) {
            rem -= ve[ptr++];
        }
        if (rem > 0) return -1;
        return ptr;
    }
};