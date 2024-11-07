class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
        int l1 = w1.length(), l2 = w2.length();

        vector<int> L(l2, -1);

        int ptr = l2 - 1;
        for (int i = l1 - 1; i >= 0; i--) {
            if (ptr >= 0 && w2[ptr] == w1[i]) {
                L[ptr] = i;
                --ptr;
            }
        }
        vector<int> ret;
        ptr = 0;
        for (int i = 0; i < l1; i++) {
            if ((ptr + 1 < l2 && L[ptr + 1] >= i + 1) || (ptr + 1 >= l2)) {
                ret.push_back(i);
                int j = i + 1;
                int ptr2 = ptr + 1;
                if (w1[i] == w2[ptr]) {
                    while (j < l1 && ptr2 < l2 && w1[j] == w2[ptr2]) {
                        ret.push_back(j);
                        j++;
                        ptr2++;
                    }
                    if (ptr2 < l2) {
                        ret.push_back(j);
                        j++;
                        ptr2++;
                    }
                }
                while (j < l1) {
                    if (ptr2 < l2 && w1[j] == w2[ptr2]) {
                        ret.push_back(j);
                        ptr2++;
                    }
                    j++;
                }
                // cout << ret.size() << '\n';
                // for (auto e : ret) {
                //     cout << e << ' ';
                // }
                // cout << '\n';
                assert ((int)ret.size() == l2);
                return ret;
            }
            if (ptr < l2 && w1[i] == w2[ptr]) {
                ret.push_back(i);
                ptr++;
            }
        }
        ret.clear();
        return ret;
    }
};