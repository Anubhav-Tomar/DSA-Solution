class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        int mask = 1;

        for(int i=0; i<32; i++){
            if((mask & n) != 0){
                ans += 1 << 31-i;
            }
            mask<<=1;
        }
        return ans;
    }
};