class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        for (auto s : operations) {
            if (s == "+") {
                scores.push_back(scores.back() + scores[scores.size() - 2]);
            } else if (s == "D") {
                scores.push_back(2 * scores.back());
            } else if (s == "C") {
                scores.pop_back();
            } else {
                scores.push_back(stoi(s));
            }
        }
        return accumulate(scores.begin(), scores.end(), 0);
    }
};