class Solution {
public:
    bool canTransform(string start, string end) {
        unordered_map<char, int> cnt;
        for (auto x : start) cnt[x]++;
        for (auto x : end) cnt[x]--;
        for (auto x : cnt) {
            if (x.second != 0) return false;
        }

        string a, b;
        for (auto c : start) if (c != 'X') a.push_back(c);
        for (auto c : end) if (c != 'X') b.push_back(c);
        bool condition_1 = a == b;

        a.clear(), b.clear();
        int tmp = 0;
        for (auto c : start) if (c != 'R') a.push_back(c);
        for (auto c : end) if (c != 'R') b.push_back(c);
        for (int i = 0; i < a.size(); i++) {
            tmp += (b[i] == 'L') - (a[i] == 'L');
            if (tmp < 0) return false;
        }
        a.clear(), b.clear();
        tmp = 0;
        for (auto c : start) if (c != 'L') a.push_back(c);
        for (auto c : end) if (c != 'L') b.push_back(c);
        for (int i = 0; i < a.size(); i++) {
            tmp += (a[i] == 'R') - (b[i] == 'R');
            if (tmp < 0) return false;
        }
        return condition_1;
    }
};