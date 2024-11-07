class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.length();
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            char cur = expression[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                vector<int> A = diffWaysToCompute(expression.substr(0, i));
                vector<int> B = diffWaysToCompute(expression.substr(i + 1, n - 1 - i));
                for (auto a : A) {
                    for (auto b : B) {
                        if (cur == '+') ret.push_back(a + b);
                        else if (cur == '-') ret.push_back(a - b);
                        else ret.push_back(a * b);
                    }
                }
            }
        }
        if (ret.empty()) {
            ret.push_back(stoi(expression));
        }
        return ret;
    }
};