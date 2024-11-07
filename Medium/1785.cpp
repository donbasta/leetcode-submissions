class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for (auto e : nums) sum += e;
        long long need = 1ll * goal - sum;
        if (need == 0) return 0;
        need = abs(need);
        return (need + limit - 1) / limit;
    }
};