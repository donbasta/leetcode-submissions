class Solution {
public:
    int halveArray(vector<int>& nums) {
        long double tot = accumulate(nums.begin(), nums.end(), (long double)0);
        long double cur = tot;
        priority_queue<long double> pq;
        for (auto e : nums) pq.push(e);
        int steps = 0;
        while (cur * 2 > tot) {
            long double tmp = pq.top();
            pq.pop();
            cur -= tmp / 2;
            pq.push(tmp / 2);
            steps++;
        }
        return steps;
    }
};