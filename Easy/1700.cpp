class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int ptr = 0;
        vector<bool> done(n);
        for (int i = 0; i < n * n; i++) {
            if (done[i % n]) continue;
            if (students[i % n] == sandwiches[ptr]) {
                done[i % n] = true;
                ptr++;
            }
            if (ptr == n) break;
        }
        return n - ptr;
    }
};