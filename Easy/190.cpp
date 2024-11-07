class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = n;
        x = ((x >> 1) & 0x55555555u) | ((x & 0x55555555u) << 1);
        x = ((x >> 2) & 0x33333333u) | ((x & 0x33333333u) << 2);
        x = ((x >> 4) & 0x0f0f0f0fu) | ((x & 0x0f0f0f0fu) << 4);
        x = ((x >> 8) & 0x00ff00ffu) | ((x & 0x00ff00ffu) << 8);
        x = ((x >> 16) & 0xffffu) | ((x & 0xffffu) << 16);
        return x;
    }
};