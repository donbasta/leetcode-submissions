class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> tmp;
        auto is_operator = [&](string s) -> bool {
            return (s == "+") || (s == "-") || (s == "*") || (s == "/");
        };
        auto operate = [&](int a, int b, string op) -> int {
            if (op == "+") return a + b;
            else if (op == "-") return a - b;
            else if (op == "*") return a * b;
            return a / b;
        };
        for (auto e : tokens) {
            if (is_operator(e)) {
                assert(tmp.size() >= 2);
                int x = tmp.back();
                tmp.pop_back();
                int y = tmp.back();
                tmp.pop_back();
                tmp.push_back(operate(y, x, e));
            } else {
                tmp.push_back(stoi(e));
            }
        }
        return tmp.back();
    }
};