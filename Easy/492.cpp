class Solution {
public:
    vector<int> constructRectangle(int area) {
        int L, R;
        for (int i = 1; i * i <= area; i++) {
            if (area % i != 0) continue;
            L = area / i, R = i;
        }
        return {L, R};
    }
};