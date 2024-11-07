class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int par[26];
        for (int i = 0; i < 26; i++) par[i] = i;
        const function<int(int)> fpar = [&](int x) -> int {
            return (par[x] == x ? par[x] : (par[x] = fpar(par[x])));
        };
        const function<void(int, int)> merge = [&](int a, int b) -> void {
            a = fpar(a), b = fpar(b);
            if (a == b) return;
            par[a] = b;
        };
        for (auto e : equations) {
            if (e[1] == '!') continue;
            merge(e[0] - 'a', e[3] - 'a');
        }
        for (auto e : equations) {
            if (e[1] == '=') continue;
            if (fpar(e[0] - 'a') == fpar(e[3] - 'a')) return false;
        }
        return true;
    }
};