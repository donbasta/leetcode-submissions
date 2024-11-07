class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, vector<int>> cnt;
        cnt[0].push_back(0);
        int tmp = 0;
        for (int i = 0; i < arr.size(); i++) {
            tmp ^= arr[i];
            cnt[tmp].push_back(i + 1);
        }
        int ans = 0;
        for (auto e : cnt) {
            vector<int> ve = e.second;
            // cout << e.first << '\n';
            // for (auto t : e.second) cout << t << ' '; 
            // cout << '\n';
            int n = ve.size();
            int tmp = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                ans += tmp * ve[i];
                tmp -= 2;
            }
            ans -= n * (n - 1) / 2;
        }
        return ans;
    }
};