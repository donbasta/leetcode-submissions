class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ret(n, -1);

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) pq.emplace(nums2[i], i);

        sort(nums1.begin(), nums1.end(), greater<>());
        int st = n;
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top().first >= nums1[i]) {
                pq.pop();
            }
            if (pq.empty()) {
                st = i;
                break;
            } else {
                ret[pq.top().second] = nums1[i];
                pq.pop();
            }
        }
        int tmp = 0;
        for (int j = st; j < n; j++) {
            while (tmp < n && ret[tmp] != -1) tmp++;
            ret[tmp++] = nums1[j];
        }

        return ret;
    }
};