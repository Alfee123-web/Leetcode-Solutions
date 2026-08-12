class Solution {
public:
    uint32_t reverseBits(int n) {
        uint32_t ans = 0;
        for(int i = 0 ; i <32 ; i++){
            uint32_t bit = n &1;
            ans =( ans << 1 )| bit;
            n >>=1;
        }
        return ans;
    }
};