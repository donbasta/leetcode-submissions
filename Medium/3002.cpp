class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = n / 2;
        set<int> s1, s2;
        for (auto e : nums1) {
            s1.insert(e);
        }
        for (auto e : nums2) {
            s2.insert(e);
        }
        set<int> p1, p2, p12;
        for (auto e : s1) {
            if (s2.count(e)) p12.insert(e);
            else p1.insert(e);
        }
        for (auto e : s2) {
            if (!s1.count(e)) p2.insert(e);
        }
        int beda = min((int)p1.size(), m) + min((int)p2.size(), m);
        int sisa = 2 * m - beda;
        beda += min(sisa, (int)p12.size());
        return beda;
    }
};