class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int B = 32;
        int ans = 0;
        for (int i = 0; i < B; i++) {
            int num1 = 0, num2 = 0;
            for (auto a : arr1) {
                num1 += ((a >> i) & 1);
            }
            for (auto a : arr2) {
                num2 += ((a >> i) & 1);
            }
            if ((num1 & 1) && (num2 & 1)) ans += (1 << i);
        }
        return ans;
    }
};