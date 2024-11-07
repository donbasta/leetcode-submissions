class Solution {
public:
    string originalDigits(string s) {
        string lmao[] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        };

        vector<int> cnt(26), freq(10);
        for (auto c : s) {
            cnt[c - 'a']++;
        }
        int tmp;
        // handle 0
        { tmp = cnt['z' - 'a']; for (auto c : lmao[0]) cnt[c - 'a'] -= tmp; freq[0] = tmp; }
        // handle 2
        { tmp = cnt['w' - 'a']; for (auto c : lmao[2]) cnt[c - 'a'] -= tmp; freq[2] = tmp; }
        // handle 4
        { tmp = cnt['u' - 'a']; for (auto c : lmao[4]) cnt[c - 'a'] -= tmp; freq[4] = tmp; }
        // handle 5
        { tmp = cnt['f' - 'a']; for (auto c : lmao[5]) cnt[c - 'a'] -= tmp; freq[5] = tmp; }
        // handle 6
        { tmp = cnt['x' - 'a']; for (auto c : lmao[6]) cnt[c - 'a'] -= tmp; freq[6] = tmp; }
        // handle 7
        { tmp = cnt['v' - 'a']; for (auto c : lmao[7]) cnt[c - 'a'] -= tmp; freq[7] = tmp; }
        // handle 8
        { tmp = cnt['g' - 'a']; for (auto c : lmao[8]) cnt[c - 'a'] -= tmp; freq[8] = tmp; }
        // handle 9
        { tmp = cnt['i' - 'a']; for (auto c : lmao[9]) cnt[c - 'a'] -= tmp; freq[9] = tmp; }
        // handle 3
        { tmp = cnt['h' - 'a']; for (auto c : lmao[3]) cnt[c - 'a'] -= tmp; freq[3] = tmp; }
        // handle 1
        { tmp = cnt['o' - 'a']; for (auto c : lmao[1]) cnt[c - 'a'] -= tmp; freq[1] = tmp; }

        string ret;
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j < freq[i]; j++) {
                ret += (char)(i + '0');
            }
        }
        return ret;
    }
};