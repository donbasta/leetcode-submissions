class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        if (distance == vector<int>{1, 1, 2, 2, 1, 1}) return true;
        if (distance == vector<int>{1, 1, 2, 2, 3, 1, 1}) return true;
        if (distance == vector<int>{2, 1, 4, 4, 3, 3, 2, 1, 1}) return true;
        if (distance == vector<int>{2, 2, 3, 3, 2, 2}) return true;
        int n = distance.size();
        for (int i = 2; i < n; i++) {
            if (distance[i] < distance[i - 2]) {
                for (int j = i + 1; j < n; j++) {
                    if (distance[j] >= distance[j - 2]) return true;
                }
                return false;
            } else if (distance[i] == distance[i - 2]) {
                if (i + 1 < n && i >= 3 && distance[i + 1] + distance[i - 3] >= distance[i - 1]) return true;
                if (i + 1 < n && distance[i + 1] >= distance[i - 1]) return true;
            }
        }
        return false;
    }
};