class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        int pi[n];
        memset(pi, 0, sizeof(pi));
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && word[i] != word[j]) {
                j = pi[j - 1];
            }
            if (word[i] == word[j]) j++;
            pi[i] = j;
        }
        int j = n - 1;
        while (j > 0) {
            if (pi[j] % k == n % k) return (n - pi[j]) / k;
            j = pi[j] - 1;
        }
        return (n + k - 1) / k;
    }
};