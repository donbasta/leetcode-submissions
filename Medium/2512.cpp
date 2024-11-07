class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string, int> feedbackWeight;
        for (auto e : positive_feedback) feedbackWeight[e] = 3;
        for (auto e : negative_feedback) feedbackWeight[e] = -1;

        const function<vector<string>(string)> getWords = [&](string s) -> vector<string> {
            vector<string> ret;
            string tmp;
            for (auto c : s) {
                if (c == ' ') {
                    ret.push_back(tmp);
                    tmp = "";
                } else {
                    tmp.push_back(c);
                }
            }
            ret.push_back(tmp);
            return ret;
        };
        
        int n = report.size();
        unordered_map<int, int> score;
        for (int i = 0; i < n; i++) {
            vector<string> wordsFromReport = getWords(report[i]);
            int tmp = 0;
            for (auto c : wordsFromReport) {
                tmp += feedbackWeight[c];
            }
            score[student_id[i]] += tmp;
        }
        vector<pair<int, int>> scoreWithID;
        for (auto e : score) {
            scoreWithID.emplace_back(e.second, e.first);
        }
        sort(scoreWithID.begin(), scoreWithID.end(), [&](pair<int, int> a, pair<int, int> b) -> bool {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(scoreWithID[i].second);
        }
        return ans;
    }
};