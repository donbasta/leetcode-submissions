class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int tot = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> pq;
        for (auto e : piles) pq.push(e);
        for (int i = 0; i < k; i++) {
            int largest = pq.top();
            pq.pop();
            tot -= largest / 2;
            pq.push(largest - (largest / 2));
        }
        return tot;
    }
};