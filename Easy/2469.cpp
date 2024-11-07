class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ret;
        ret.push_back(celsius + 273.15);
        ret.push_back(celsius * 1.8 + 32);
        return ret;
    }
};