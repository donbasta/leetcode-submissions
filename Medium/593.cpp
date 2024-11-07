class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) return false;
        auto cek = [&](vector<int>& x1, vector<int>& x2, vector<int>& x3, vector<int>& x4) -> bool {
            bool ret = true;
            ret &= (1ll * (x1[0] - x3[0]) * (x2[0] - x4[0]) + 1ll * (x1[1] - x3[1]) * (x2[1] - x4[1]) == 0);
            ret &= ((x1[0] + x3[0] == x2[0] + x4[0]) && (x1[1] + x3[1] == x2[1] + x4[1]));
            ret &= (1ll * (x1[0] - x2[0]) * (x2[0] - x3[0]) + 1ll * (x1[1] - x2[1]) * (x2[1] - x3[1]) == 0);
            return ret;
        };

        bool ok = false;
        ok |= cek(p1, p2, p3, p4);
        ok |= cek(p1, p2, p4, p3);
        ok |= cek(p1, p3, p2, p4);
        ok |= cek(p1, p3, p4, p2);
        ok |= cek(p1, p4, p2, p3);
        ok |= cek(p1, p4, p3, p2);
        return ok;
    }
};