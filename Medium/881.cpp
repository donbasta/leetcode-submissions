class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end(), greater<>());
        int idx = n - 1;
        int ans = 0;
        for (int i = 0; i <= idx; i++) {
            if ((i < idx) && (people[i] + people[idx] <= limit)) {
                ans++;
                idx--;
            } else {
                ans++;
            }
        }
        return ans;
    }
};