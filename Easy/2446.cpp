class Solution {
public:
    bool haveConflict(vector<string>& e1, vector<string>& e2) {
        int a1 = stoi(e1[0].substr(0, 2)) * 60 + stoi(e1[0].substr(3, 2));
        int b1 = stoi(e1[1].substr(0, 2)) * 60 + stoi(e1[1].substr(3, 2));
        int a2 = stoi(e2[0].substr(0, 2)) * 60 + stoi(e2[0].substr(3, 2));
        int b2 = stoi(e2[1].substr(0, 2)) * 60 + stoi(e2[1].substr(3, 2));
        if (a2 > b1 || a1 > b2) return false;
        return true;
    }
};