class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> cnt(26);
        for (auto c : sentence) cnt[c - 'a']++;
        return *min_element(cnt.begin(), cnt.end()) >= 1;
    }
};