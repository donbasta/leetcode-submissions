class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int hLogin = stoi(loginTime.substr(0, 2));
        int mLogin = stoi(loginTime.substr(3, 2));
        int hLogout = stoi(logoutTime.substr(0, 2));
        int mLogout = stoi(logoutTime.substr(3, 2)); 
        int xLogin = hLogin * 60 + mLogin;
        int xLogout = hLogout * 60 + mLogout;
        if (xLogout < xLogin) xLogout += 60 * 24;
        return max(0, (xLogout / 15) - ((xLogin + 14) / 15));
    }
};