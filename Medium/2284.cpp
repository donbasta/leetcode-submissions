class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        const function<int(string)> countWord = [&](string s) -> int {
            int ret = 0;
            for (auto c : s) {
                if (c == ' ') ret++;
            }
            return ret + 1;
        };
        unordered_map<string, int> wordCount;
        int n = senders.size();
        for (int i = 0; i < n; i++) {
            wordCount[senders[i]] += countWord(messages[i]);
        }
        string who = "";
        int howMany = -1;
        for (auto e : wordCount) {
            if (e.second > howMany) {
                howMany = e.second;
                who = e.first;
            } else if (e.second == howMany) {
                who = max(who, e.first);
            }
        }
        return who;
    }
};