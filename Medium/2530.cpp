class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> pq;
        for (auto e : nums) pq.push(e);
        for (int i = 0; i < k; i++) {
            int largest = pq.top();
            pq.pop();
            score += largest;
            pq.push((largest + 2) / 3);
        }
        return score;
    }
};