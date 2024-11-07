class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_map<int, bool> st;
        for (auto e : startWords) {
            int tmp = 0;
            for (auto c : e) tmp ^= (1 << (c - 'a'));
            st[tmp] = true;
        }
        int ret = 0;
        for (auto e : targetWords) {
            int tmp = 0;
            for (auto c : e) tmp ^= (1 << (c - 'a'));
            for (auto c : e) {
                tmp ^= (1 << (c - 'a'));
                if (st.find(tmp) != st.end()) {
                    ret++;
                    break;
                }
                tmp ^= (1 << (c - 'a'));
            }
        }
        return ret;
    }
};