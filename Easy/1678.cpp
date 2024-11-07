class Solution {
public:
    string interpret(string command) {
        int n = command.size();
        int itr = 0;
        string ret;
        while (itr < n) {
            if (command[itr] == 'G') {
                ret.push_back('G');
                itr++;
            } else {
                assert (command[itr] == '(');
                if (command[itr + 1] == ')') {
                    ret.push_back('o');
                    itr += 2;
                } else {
                    ret += "al";
                    itr += 4;
                }
            }
        }
        return ret;
    }
};