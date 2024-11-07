class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) {
        using ll = long long;
        int n = op.size();
        --k;

        int offset = 0;
        for (int i = n - 1; i >= 0; i--) {
            int cur = op[i];
            
            if (cur == 0) {
                if ((i < 60) && (k >= (1ll << i))) {
                    k -= (1ll << i);
                }
            } else {
                if ((i < 60) && (k >= (1ll << i))) {
                    offset++;
                    k -= (1ll << i);
                }
            }
            // cout << i << ' ' << k << '\n';
        }
        offset %= 26;
        return (char)(offset + 'a');
    }
};