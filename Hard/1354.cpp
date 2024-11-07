class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;
        long long sum = accumulate(target.begin(), target.end(), 0ll);
        priority_queue<int> pq;
        for (auto e : target) pq.push(e);
        while (true) {
            int greatest = pq.top();
            if (greatest == 1) {
                break;
            }
            pq.pop();
            long long other = sum - greatest;
            if (other == 1) return true;
            if (greatest <= other) return false;
            
            int prev = greatest % other;
            if (prev == 0) return false;
            pq.push(prev);
            sum = prev + other;
        }
        return true;
    }
};