class Solution {
public:
    int partitionString(string s) {
        set<char> se;
        int ans = 1;
        for (auto c : s) {
            if (se.find(c) != se.end()) {
                ans++;
                se.clear();  
            }
            se.insert(c);
        }
        return ans;
    }
};