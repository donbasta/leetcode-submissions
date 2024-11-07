class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool heavy = mass >= 100;
        bool bulky = (length >= 10000 || width >= 10000 || height >= 10000 || 1ll * length * width * height >= 1000000000ll);
        if (bulky && heavy) return "Both";
        else if (bulky) return "Bulky";
        else if (heavy) return "Heavy";
        return "Neither";
    }
};