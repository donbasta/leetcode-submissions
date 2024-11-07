class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sim;
        int ipush = 0, ipop = 0;
        int n = pushed.size();
        while (ipush < n || ipop < n) {
            if (sim.empty() || (!sim.empty() && popped[ipop] != sim.top())) {
                if (ipush == n) return false;
                sim.push(pushed[ipush++]);
            } else if (!sim.empty() && popped[ipop] == sim.top()) {
                sim.pop();
                ipop++;
            }
        }
        return true;
    }
};