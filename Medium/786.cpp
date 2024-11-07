class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int, int>> ve;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ve.emplace_back(i, j);
            }
        }
        sort(ve.begin(), ve.end(), [&](pair<int, int> a, pair<int, int> b) -> bool {
            return arr[a.first] * arr[b.second] < arr[a.second] * arr[b.first];
        });
        return vector<int>{arr[ve[k - 1].first], arr[ve[k - 1].second]};
    }
};