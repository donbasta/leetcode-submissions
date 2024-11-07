class Solution {
public:
    int nextBeautifulNumber(int n) {
        n++;

        auto beau = [&](int x) -> bool {
            vector<int> cnt(10);
            while (x) {
                cnt[x % 10]++;
                x /= 10;
            }
            for (int i = 0; i < 10; i++) {
                if (cnt[i] != 0 && cnt[i] != i) return false;
            }
            return true;
        };

        while (true) {
            if (beau(n)) break;
            n++;
            while (n % 10 == 0 || n % 100 == 11 || n % 1000 == 222 || n % 10000 == 3333) n++;
        }
        return n;
    }
};