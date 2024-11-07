class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        auto lambda = [&](int a, int b){return __gcd(a, b); };
        int gcdAll = accumulate(nums.begin(), nums.end(), 0, lambda);  
        return gcdAll == 1;
    }
};