class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<unordered_map<char, int>> hehe;
        unordered_map<char, int> last;
        for (int i = 0; i < garbage.size(); i++) {
            unordered_map<char, int> tmp;
            for (auto c : garbage[i]) {
                tmp[c]++;
            }
            for (auto c : "GMP") {
                if (tmp[c] > 0) last[c] = i;
            }
            hehe.push_back(tmp);
        }
        int time = 0;
        for (auto c : "MPG") {
            for (int i = 0; i < garbage.size(); i++) {
                time += hehe[i][c];
                if (last[c] == i) break;
                if (i < garbage.size() - 1) {
                    time += travel[i];
                }
            }
        }
        return time;
    }
};