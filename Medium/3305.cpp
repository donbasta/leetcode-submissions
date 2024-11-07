class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        bool is_vw[26];
        memset(is_vw, false, sizeof(is_vw));
        int id[26];
        memset(id, -1, sizeof(id));
        is_vw[0] = is_vw[4] = is_vw[8] = is_vw[14] = is_vw[20] = true;
        id[0] = 0;
        id[4] = 1;
        id[8] = 2;
        id[14] = 3;
        id[20] = 4;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int cn = 0;
                int tmp[5];
                memset(tmp, 0, sizeof(tmp));
                for (int kk = i; kk <= j; kk++) {
                    if (is_vw[word[kk] - 'a']) {
                        tmp[id[word[kk] - 'a']]++;
                    } else cn++;
                }
                ans += ((*min_element(tmp, tmp + 5) >= 1) && (cn == k));
            }
        }
        return ans;
    }
};