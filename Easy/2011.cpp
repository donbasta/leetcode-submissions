class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int cur = 0;
        for (auto o : operations) {
            if (o.back() == '+' || o[0] == '+') cur++;
            else cur--;
        }
        return cur;
    }
};