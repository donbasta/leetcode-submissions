class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> sm(k);
        int n = energy.size();
        int ans = -2e9;
        for (int i = n - 1; i >= 0; i--) {
            sm[i % k] += energy[i];
            ans = max(ans, sm[i % k]);
        }
        return ans;
    }
};