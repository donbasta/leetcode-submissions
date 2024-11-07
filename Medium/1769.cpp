class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        int numBoxes = (boxes[0] == '1');
        int tmp = 0;
        for (int i = 1; i < n; i++) {
            tmp += ((boxes[i] == '1') ? i : 0);
            numBoxes += (boxes[i] == '1');
        }
        vector<int> T = {tmp};
        int countLeft = (boxes[0] == '1');
        int countRight = numBoxes - countLeft;
        for (int i = 1; i < n; i++) {
            tmp += countLeft;
            tmp -= countRight;
            if (boxes[i] == '1') {
                countLeft++, countRight--;
            }
            T.push_back(tmp);
        }
        return T;
    }
};