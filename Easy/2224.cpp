class Solution {
public:
    int convertTime(string current, string correct) {
        int a = stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3, 2));
        int b = stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3, 2));
        int dif = b - a;
        int ret = dif / 60;
        dif %= 60;
        ret += dif / 15;
        dif %= 15;
        ret += dif / 5;
        dif %= 5;
        ret += dif;
        return ret;
    }
};