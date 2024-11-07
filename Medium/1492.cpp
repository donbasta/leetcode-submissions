class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> divs;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divs.push_back(i);
                if (i * i != n) divs.push_back(n / i);
            }
        }
        if (divs.size() < k) return -1;
        sort(divs.begin(), divs.end());
        return divs[k - 1];
    }
};