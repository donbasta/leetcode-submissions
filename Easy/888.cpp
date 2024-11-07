class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        using ll = long long;
        ll a = accumulate(aliceSizes.begin(), aliceSizes.end(), 0ll);
        ll b = accumulate(bobSizes.begin(), bobSizes.end(), 0ll);

        assert (abs(a - b) % 2 == 0);
        vector<int> ret(2);

        set<int> se;
        for (auto e : bobSizes) {
            se.insert(e);
        }

        ll dif = (a - b) / 2;
        for (auto e : aliceSizes) {
            if (se.count(e - dif)) {
                ret[0] = e;
                ret[1] = e - dif;
                return ret;
            }
        }
        assert(false);
        return ret;

        // a + bb - aa = b + aa - bb
        // a - b = 2 (aa - bb)


    }
};