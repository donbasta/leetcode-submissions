class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long M = 1ll * mass;
        for (auto c : asteroids) {
            if (1ll * c > M) return false;
            M += c;
        }
        return true;
    }
};