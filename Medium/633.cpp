class Solution {
public:
    bool judgeSquareSum(int c) {
        using ll = long long;
        ll cc = c;
        for (ll a = 0; a * a <= cc; a++) {
            ll b2 = c - a * a;
            ll hehe = sqrtl(b2);
            if (hehe * hehe == b2) return true;
        }
        return false;
    }
};