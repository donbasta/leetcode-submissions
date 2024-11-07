class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> fi(n), la(n);
        for (int i = 0; i < n; i++) {
            la[i] = nums[i] % 10;
            fi[i] = nums[i];
            while (fi[i] >= 10) {
                fi[i] /= 10;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += __gcd(fi[i], la[j]) == 1;
            }
        }
        return ans;
    }
};