class Solution {
public:
    vector<int> closestDivisors(int num) {
        int mn = num;
        vector<int> ans = {1, num + 1};
        for (auto e : {num + 1, num + 2}) {
            for (int i = 1; i * i <= e; i++) {
                if (e % i == 0) {
                    int j = e / i;
                    if (j - i <= mn) {
                        mn = j - i;
                        ans = {i, j};
                    }
                }
            }
        }
        return ans;
    }
};