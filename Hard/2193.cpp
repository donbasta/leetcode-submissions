class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        vector<int> pos[26];
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) pos[s[i] - 'a'].push_back(i);
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                vector<pair<int, int>> tmp;
                for (auto x : pos[i]) tmp.emplace_back(x, 0);
                for (auto x : pos[j]) tmp.emplace_back(x, 1);
                sort(tmp.begin(), tmp.end());
                string st;
                for (auto e : tmp) st.push_back((char)(e.second + '0'));
                int len = st.length();
                int itr = 0;
                while (itr < len / 2) {
                    if (st[itr] == st[len - 1 - itr]) {
                        itr++;
                        continue;
                    }
                    int l = itr + 1;
                    while (st[l] == st[itr]) l++;
                    int r = len - 2 - itr;
                    while (st[r] == st[len - 1 - itr]) r--;
                    ans += min(l - itr, (len - 1 - itr) - r);
                    if (l - itr >= (len - 1 - itr) - r) {
                        swap(st[r], st[len - 1 - itr]);
                    } else {
                        swap(st[l], st[itr]);
                    }
                    itr++;
                }
            }
        }
        return ans;
    }
};