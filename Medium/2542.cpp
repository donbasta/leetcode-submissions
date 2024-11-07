class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ve;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            ve.emplace_back(nums2[i], nums1[i]);
        }
        sort(ve.begin(), ve.end(), greater<pair<int, int>>());
        multiset<int> se;
        // priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += ve[i].second;
            se.emplace(ve[i].second);
            // pq.emplace(ve[i].second);
        }

        long long ans = 1ll * (sum) * (ve[k - 1].first);
        for (int i = k; i < n; i++) {
            sum -= *se.begin(); se.erase(se.begin()); 
            sum += ve[i].second; se.insert(ve[i].second);
            // sum -= pq.top(); pq.pop();
            // sum += ve[i].second; pq.push(ve[i].second);
            ans = max(ans, 1ll * sum * ve[i].first);
        }
        return ans;
    }
};