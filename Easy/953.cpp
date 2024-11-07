class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int sz = words.size();
        vector<int> pos(26);
        for (int i = 0; i < 26; i++) {
            pos[order[i] - 'a'] = i;
        }

        auto gr = [&](const string& p, const string& q) -> bool {
            int np = p.length(), nq = q.length();
            int itr = 0;
            while (itr < min(np, nq)) {
                if (pos[p[itr] - 'a'] < pos[q[itr] - 'a']) return false;
                else if (pos[p[itr] - 'a'] > pos[q[itr] - 'a']) return true;
                itr++;
            }
            if (np > nq) return true;
            return false;
        };

        for (int i = 1; i < sz; i++) {
            if (gr(words[i - 1], words[i])) return false;
        }
        return true;
    }
};