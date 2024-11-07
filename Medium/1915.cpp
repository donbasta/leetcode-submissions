class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> cnt(1024);
        int tmp = 0;
        cnt[0]++;
        
        using ll = long long;
        ll ret = 0;
        for (auto c : word) {
            int dig = c - 'a';
            tmp ^= (1 << dig);
            ret += cnt[tmp];
            for (int i = 0; i < 10; i++) {
                ret += cnt[tmp ^ (1 << i)];
            }
            cnt[tmp]++;
        }
        return ret;
    }
};