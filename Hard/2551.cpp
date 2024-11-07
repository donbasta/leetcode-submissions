class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> lmao;
        for (int i = 0; i < n - 1; i++) {
            lmao.push_back(weights[i] + weights[i + 1]);
        }
        sort(lmao.begin(), lmao.end());
        long long ans = 0;
        for (int i = 0; i < k - 1; i++) {
            ans += lmao[n - 2 - i] - lmao[i];
        }
        return ans;
    }
};