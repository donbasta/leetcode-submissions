class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int> de;
        for (int i = 0; i < n; i++) de.push_back(i);
        int cur = 0;
        int sisa = n;
        while (de.size() > 1) {
            for (int i = 0; i < k - 1; i++) {
                int front = de.front();
                de.pop_front();
                de.push_back(front);
            }
            de.pop_front();
        }
        return de.front() + 1;
    }
};